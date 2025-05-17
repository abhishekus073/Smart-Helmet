# include<SoftwareSerial.h>

// software serial Ports
const byte tx = 3;
const byte rx = 4;


// wifi name and password
String ssid = "smart";
String password = "123456789";

boolean found = false;

//thingspeak
String api = "HY7KCVKU2TWTK5AH";   //
String host = "api.thingspeak.com";
String port = "80";

// initiallize the user defined functions
SoftwareSerial esp01(rx, tx);

void sendcommand(String command, int maxtime, char readreply[]);
void connectwifi();
void senddata();
void ini_iot();

void sendcommand(String command, int maxtime, char readreply[])
{
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");


  while (maxtime != 0)
  {
    esp01.println(command);
    if (esp01.find(readreply)) //ok
    {
      found = true;
      Serial.println("OK Done");
      break;
    }
    maxtime--;
  }


  if (found == false)
  {
    Serial.println("Fail");
  }

  found = false;

}




void connectwifi()
{
  sendcommand("AT", 5, "OK");
  sendcommand("AT+CWMODE=1", 5, "OK");
  sendcommand("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"", 20, "OK");
}


void senddata(String getData2)
{
  //https://api.thingspeak.com/update?api_key=RHUC7F7LC4WIMILN&field1=0
  String getData1 = "GET /update?api_key=" + api;
  //String getData2 = "&field1="+String(value);
  sendcommand("AT+CIPMUX=1", 2, "OK");
  sendcommand("AT+CIPSTART=0,\"TCP\",\"" + host + "\"," + port, 10, "OK");
  sendcommand("AT+CIPSEND=0," + String(getData1.length() + getData2.length() + 2), 7, ">");

  delay(20);
  esp01.println(getData1 + getData2);
  Serial.println(getData1 + getData2);
  delay(1500);
  //sendcommand("AT+CIPCLOSE=0", 5 , "OK");
  Serial.println("---------------------------");
}

void ini_iot()
{

  Serial.begin(9600);
  esp01.begin(115200);
//  Serial.println("IOT Project");
  delay(1000);
  connectwifi();
}
