int analogValue = 0;
int ledValue = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  analogValue = analogRead(A3);
  Serial.println(analogValue);
  
  ledValue = map(analogValue, 0, 1023, 0, 255);
  Serial.println(ledValue);
  
  analogWrite(13, ledValue);
  delay(10);
}