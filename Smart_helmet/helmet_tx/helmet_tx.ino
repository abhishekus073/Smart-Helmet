#define   x   A0              // ADXl sensor          //helmet part
#define   y   A1
#define   z   A2

#define mq_3  A4              // Alcoholic sensor

#define push 8                // push button

#define t1  4                 // RF module
#define t2  5
#define t3  6

unsigned short level, X, Y, Z;
int ret_val;
int Alchol_thres = 60;


#define Accident_off digitalWrite(t1,0);
#define Accident_on  digitalWrite(t1,1);
#define Alcohol_off  digitalWrite(t2,0);
#define Alcohol_on   digitalWrite(t2,1);
#define helmet_off   digitalWrite(t3,0);
#define helmet_on    digitalWrite(t3,1);


int dir_print();

void setup()
{
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);

  pinMode(mq_3, INPUT);
  pinMode(push, INPUT);

  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
  helmet_off;
  Accident_off;
  Alcohol_off;
  Serial.begin(9600);
}

void loop()
{
  int level=map(analogRead(mq_3),0,1023,0,100);
  Serial.println(level);
  
  int button=digitalRead(push);
  Serial.println(button);
  delay(1000);
  if (level < Alchol_thres && button == 1)
  {
    helmet_on;
   
    Serial.println ("heii:");
    while (1)
    {
      if (digitalRead(push) == 0 || level > Alchol_thres)
      {
        break;
      }
      //      char count = 5;
      ret_val = dir_print();
      int level=map(analogRead(mq_3),0,1023,0,100);
      Serial.println(level);
  
      if (ret_val == 0 && digitalRead(push) == 1 && level < Alchol_thres)
      {
        Serial.println("no accident");
        helmet_on;
        Alcohol_off;
        Accident_off;
        delay(100);
      }
     else if(ret_val == 0 && digitalRead(push) == 1 && level >Alchol_thres)
      {
       Alcohol_on;
       Serial.println("alcohal");
        delay(100);
      }
      else
      {
        Accident_on;                // to stop engine
        Serial.println("accident");
      }
//      delay(200);
    }

  }
  else
  {
    helmet_off;
    Accident_off;
    Alcohol_off;
  }
 
  delay(500);

  
}



int dir_print()
{
  X = analogRead(x);
  Y = analogRead(y);
  Z = analogRead(z);

  Serial.println(X);
  Serial.println(Y);
  Serial.println(Z);
  Serial.println("..............");
  delay(1000);
  //  if (X > 400 || X < 270 || Y > 400 || Y < 270)
  if (Z < 430)
  {
    // int m=1;
    return 1;

  }
  else
  {
    //int m=0;
    return 0;
  }

}
