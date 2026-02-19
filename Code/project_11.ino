const int buttonPin = 12;
const int buzzerPin = 1;
const int blueLED = 6;
const int redLED = 7;

bool state = false;
bool lastButton = HIGH;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  digitalWrite(redLED, HIGH);
}

void loop()
{
  bool currentButton = digitalRead(buttonPin);
  
  if (lastButton == HIGH && currentButton == LOW) {
    state = !state;
    
    if (state) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(blueLED, HIGH);
      digitalWrite(redLED, LOW);
    } else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(redLED, HIGH);
    }
    delay(200);
  }
  lastButton = currentButton;
}