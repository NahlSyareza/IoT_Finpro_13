#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6fSuUMh-m"
#define BLYNK_TEMPLATE_NAME "Zang Zing"
#define BLYNK_AUTH_TOKEN "iccuJhsXcjRIX20sFM75onKmGgwY_R_P"

#define IR_DC_MODE_VPIN V10
#define IR_DC_VALUE_VPIN V12

#include <Arduino.h>
#include <FreeRTOSConfig.h>
#include <ESP32Servo.h>
#include <BlynkSimpleEsp32.h>

#define INPUT_ENTER 23
#define INPUT_EXIT 22

#define PHYSICAL_BUILD 21

#define OUTPUT_POWER 25

Servo servo;
BaseType_t xSetPowerTask;

int people = 0;
bool enter_changed = false;
bool exit_changed = false;

const char *ssid = "Wokwi-GUEST";
const char *password = "";

static int IR_DC_MODE = 0;
static int IR_DC_VALUE = 0;

BLYNK_WRITE(IR_DC_MODE_VPIN)
{
  IR_DC_MODE = param.asInt();
  Serial.println("Vrombop");
}

BLYNK_WRITE(IR_DC_VALUE_VPIN)
{
  IR_DC_VALUE = param.asInt();
  Serial.println("Zang zing");
}

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

    int formula = ((float)people / 5) * 180;

    formula = !IR_DC_MODE ? formula : IR_DC_VALUE;

    servo.write(formula);

    if (people < 5)
    {
      sprintf(buff, "People is %d (Power: %.2f)", people, formula);
      // Serial.println(buff);
    }
    else
    {
      sprintf(buff, "ZENKAIII! People is more than equal to %d (Power: %.2f)", people, formula);
      // Serial.println(buff);
    }

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  Blynk.syncVirtual(IR_DC_MODE_VPIN);
  Blynk.syncVirtual(IR_DC_VALUE_VPIN);

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
  Blynk.run();
}