#include <Arduino.h>
#include <FreeRTOSConfig.h>

#define IN1 26
#define IN2 25
#define EN1 27

#define PWM_CHN 0     // Channel 0
#define LEDC_TIMER 0  // Timer 0
#define PWM_RES 8     // 8-bit resolution (0-255)
#define PWM_FREQ 1000 // Frequency in Hz (5 kHz)

void setup()
{
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // pinMode(LEDC_PIN, OUTPUT);

  if (!ledcSetup(PWM_CHN, PWM_FREQ, PWM_RES))
  {
    Serial.println("LEDC setup failed!");
    while (1)
      ; // Halt if setup fails
  }

  ledcAttachPin(EN1, PWM_CHN);

  ledcWrite(PWM_CHN, 180);

  Serial.println("Vrombop:");
}

void loop()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // for (int duty = 0; duty <= 255; duty++)
  // {
  //   ledcWrite(PWM_CHN, duty); // Set duty cycle
  //   delay(10);
  // }

  // for (int duty = 255; duty >= 0; duty--)
  // {
  //   ledcWrite(PWM_CHN, duty);
  //   delay(10);
  // }

  int delay_val = 1000;

  int duty = 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);

  duty += 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);

  duty += 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);

  duty += 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);

  duty += 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);

  duty += 32;
  ledcWrite(PWM_CHN, duty);
  Serial.println(duty);
  delay(delay_val);
}