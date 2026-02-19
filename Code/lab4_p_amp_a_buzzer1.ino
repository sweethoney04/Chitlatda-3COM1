#define SPEAKER 10
#define BTN 4
#define FREQ 50

int startFreq = FREQ;
int endFreq = 4000;
int btnState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop()
{
  btnState = digitalRead(BTN);
  Serial.println(btnState);
  if(btnState == HIGH) {
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    for(startFreq; startFreq < endFreq; startFreq += 100){
      tone(SPEAKER, startFreq);
      delay(100);
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  if (startFreq > endFreq) {
    noTone(SPEAKER);
    startFreq = FREQ;
  }
}