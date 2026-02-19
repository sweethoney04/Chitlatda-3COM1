#include <Servo.h>

Servo myservo; //create servo object to control a servo

int potpin = A5;
int val;

void setup()
{
  Serial.begin(9600);
  myservo.attach(7);
}

void loop()
{
  val = analogRead(potpin);
  Serial.print("pot = ");
  Serial.print(val);
  Serial.print(", servo = ");
  val = map(val, 0, 1023, 0, 180);
  
  Serial.println(val);
  myservo.write(val);
  delay(15);
}