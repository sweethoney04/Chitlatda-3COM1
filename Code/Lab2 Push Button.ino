int buttonState = 0;

void setup()
{
  pinMode(3, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(3);
  if (buttonState == HIGH) {
    Serial.println("Button HIGH");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.println("Button LOW");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(10);
}