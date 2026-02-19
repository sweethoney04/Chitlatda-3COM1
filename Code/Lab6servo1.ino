#include <Servo.h>

Servo myservo; //create servo object to
void setup()
{
  Serial.begin(9600);
  myservo.attach(7);
}

void loop()
{
  for(int i = 0; i <= 180; i++){
    
    myservo.write(i);
    
    Serial.println(i);
    delay(15);
  }
  delay(500);
  for (int i = 180; i >= 0; i--){
    myservo.write(i);
    
    Serial.println(i);
    delay(15);
  }
  delay(500);
}