//Masukkan BLYNK_AUTH_TOKEN, TEMPLATE_ID, dan TEMPLATE_NAME dari aplikasi Blynk
#define BLYNK_TEMPLATE_ID "Template_ID"
#define BLYNK_TEMPLATE_NAME "Template_Name"
#define BLYNK_AUTH_TOKEN "Auth_Token"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "SSID";
char pass[] = "Password";


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;  

//Konfigurasi pin yang digunakan
int M1PWM = 25;  //pwm motor 1
int M2PWM = 26;  //pwm motor 2
int M1F = 4;     //in 1
int M1R = 5;     //in 2
int M2F = 12;    //in 3
int M2R = 13;    //in 4

int pinValue1;
int pinValue2;

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  analogWrite(M1PWM, pinValue1);
  Blynk.virtualWrite(V1, pinValue1);
  Serial.print("V1 Slider Value is ");
  Serial.println(pinValue1);
}

BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt();
  analogWrite(M2PWM, pinValue2);
  Blynk.virtualWrite(V2, pinValue2);  // Mengubah V1 menjadi V2
  Serial.print("V2 Slider Value is ");
  Serial.println(pinValue2);
}

void setup()
{
  pinMode(M1PWM, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2R, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
