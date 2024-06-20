#include <Servo.h>
Servo myservo;

int pir=7;           // digital pin for pir motion sensor

void setup()
{
  pinMode(pir,INPUT);
  myservo.attach(8);  // digital pin for servo motor
  Serial.begin(9600);
}

void loop()
{
  int x = digitalRead(pir);
  Serial.println(x);
  if(x==HIGH)
{
    myservo.write(180);
     delay(1);
  }
 
  else{
    
    myservo.write(-300);
    
  }
  
 

  }


