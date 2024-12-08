#include <Arduino.h>
#include <FreeRTOSConfig.h>
#include <ESP32Servo.h>

#define INPUT_ENTER 23
#define INPUT_EXIT 22

#define PHYSICAL_BUILD 21

#define OUTPUT_POWER 25

Servo servo;
BaseType_t xSetPowerTask;

int people = 0;
bool enter_changed = false;
bool exit_changed = false;

void vSetPowerTask(void *pvParameters)
{
  char buff[255];
  while (1)
  {
    if (digitalRead(INPUT_ENTER) == LOW)
    {
      if (!enter_changed)
      {
        people = people + 1 > 5 ? 5 : people += 1;
        enter_changed = true;
      }
    }
    else
    {
      enter_changed = false;
    }

    if (digitalRead(INPUT_EXIT) == LOW)
    {
      if (!exit_changed)
      {
        people = people - 1 < 0 ? 0 : people -= 1;
        exit_changed = true;
      }
    }
    else
    {
      exit_changed = false;
    }

    float formula = ((float)people / 5) * 180;
    servo.write(formula);

    if (people < 5)
    {
      sprintf(buff, "People is %d (Power: %.2f)", people, formula);
      Serial.println(buff);
    }
    else
    {
      sprintf(buff, "ZENKAIII! People is more than equal to %d (Power: %.2f)", people, formula);
      Serial.println(buff);
    }

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  xSetPowerTask = xTaskCreate(vSetPowerTask, "Set Power", 4096, NULL, 0, NULL);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  servo.setPeriodHertz(50);
  servo.attach(PHYSICAL_BUILD);

  pinMode(INPUT_ENTER, INPUT_PULLUP);
}

void loop()
{
  // put your main code here, to run repeatedly:
}