#include <Servo.h>

Servo myServo;  // create servo object
int potPin = A5;  // potentiometer connected to A0
int led1 = 4;    // LED1 pin
int led2 = 1;    // LED2 pin
int potVal;       // variable to store potentiometer value
int servoPos;     // variable for servo position

void setup() {
  myServo.attach(0); // attach servo to pin 9
  pinMode(led1, OUTPUT); // LED1 as output
  pinMode(led2, OUTPUT); // LED2 as output
}

void loop() {
  // read potentiometer (0-1023) and map to servo angle (0-180)
  potVal = analogRead(potPin);
  servoPos = map(potVal, 0, 1023, 0, 180);
  
  // move servo
  myServo.write(servoPos);
  
  // control LEDs
  if(servoPos > 90){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  
  delay(15); // small delay for smooth servo movement
}
