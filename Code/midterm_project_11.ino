const int buttonPin = 13;
const int led1 = 10; 
const int led2 = 11; 
const int led3 = 12;  

int mode = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Button Debounce & Mode Switching
  if (buttonState == LOW && lastButtonState == HIGH) {
    mode++;
    if (mode > 3) mode = 0;
    delay(200); // Slight delay to prevent double-triggering
  }
  lastButtonState = buttonState;

  // --- Mode 0: Sequential (1 -> 2 -> 3) ---
  if (mode == 0) {
    int sequence[] = {led1, led2, led3};
    for(int i = 0; i < 3; i++) {
      digitalWrite(sequence[i], HIGH);
      delay(300);
      digitalWrite(sequence[i], LOW);
      // Check button during sequence for better responsiveness
      if(digitalRead(buttonPin) == LOW) break; 
    }
  }

  //  Mode 1: 
  else if (mode == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(300);
  }

  //  Mode 2:
  else if (mode == 2) {
    int reverseSequence[] = {led3, led2, led1};
    for(int i = 0; i < 3; i++) {
      digitalWrite(reverseSequence[i], HIGH);
      delay(300);
      digitalWrite(reverseSequence[i], LOW);
      if(digitalRead(buttonPin) == LOW) break;
    }
  }

  // Mode 3: All Off 
  else if (mode == 3) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
