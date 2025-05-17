#include<TinyGPS.h>                  // receiver part
#include"esp02_iot.h"

const int r1 = 5, r2 = 6, r3 = 7, relay_pin = 8;
float lat, lon;

TinyGPS gps;

int flag, helmet_status, alcohol_status, Engine_status, accident_status;


long Start1, Start;

void gps_read();
// void send_sms(String , String );




void setup()
{
  //  Serial.begin(9600);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  pinMode(r3, INPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, 1);
  Start = millis();
  Start1 = millis();
  ini_iot();
  //  digitalWrite(relay_pin, 0);
  //  delay(5000);
  //  digitalWrite(relay_pin, 1);
}

void loop()
{
  Serial.println(digitalRead(r1));
  Serial.println(digitalRead(r2));
  Serial.println(digitalRead(r3));
  Serial.println(".............");

  delay(500);
  gps_read();

  if (digitalRead(r1) == 0 && digitalRead(r2) == 0 && digitalRead(r3) == 1)
  {
    digitalWrite(relay_pin, 0);
    alcohol_status = 0;
    Engine_status = 1;
    accident_status = 0;
    helmet_status = 1;
    flag = 0;
  }

  else if (digitalRead(r1) == 0  && digitalRead(r2) == 0  && digitalRead(r3) == 0 )
  {
    digitalWrite(relay_pin, 1);
    Engine_status = 0;
    accident_status = 0;
    helmet_status = 0;
    alcohol_status = 1;
    flag = 0;
  }

    else if (digitalRead(r1) == 0 && digitalRead(r2) == 1 && digitalRead(r3) == 1)
    {
      digitalWrite(relay_pin, 1);
      alcohol_status = 1;
      Engine_status = 0;
      accident_status = 0;
      helmet_status = 0;
      flag = 0;
    }

  
  else if (digitalRead(r1) == 1 && digitalRead(r2) == 0 && digitalRead(r3) == 1 )     
  {
    digitalWrite(relay_pin, 1);
    Engine_status = 0;
    helmet_status = 1;
    accident_status = 1;
  }

  String getData2 = "&field1=" + String(accident_status) + "&field2=" + String(helmet_status) + "&field3=" + String(alcohol_status) + "&field4=" + String(lat) + "&field5=" + String(lon) + "&field6=" + String(Engine_status);

  if (millis() - Start > 40000)
  {
    senddata(getData2);
    Start = millis();
  }

  
}

void gps_read()
{
  Start1 = millis();
  while (millis() - Start1 < 2000)
  {
    while (Serial.available())
      if (gps.encode(Serial.read()))
      {
        gps.f_get_position(&lat, &lon);
      }
  }

}
