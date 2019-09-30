const int button = 2;
const int green = 10;
const int yellow = 11;
const int red = 12;
const int pRed = 7;
const int pGreen = 9;
const int greenTime = 10000;
const int crossTime = 10000;
const int blinkCrossTime = 6000;
int buttonState;
int parameter = 0;
unsigned long currentTime = 0;



void setup() {
  pinMode (buttonState, INPUT);
  pinMode (green, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (pRed, OUTPUT);
  pinMode (pGreen, OUTPUT);

  digitalWrite(green, HIGH);
  digitalWrite(pRed, HIGH);
}

void loop() {
  buttonState = digitalRead (button);
  if (buttonState == HIGH){
    parameter = 1;
  }
  if ((millis() - currentTime > greenTime) && (parameter == 1)){
    digitalWrite (green, LOW);
    digitalWrite (yellow, HIGH);
    delay (2000);
    digitalWrite (yellow, LOW);
    digitalWrite (red, HIGH);
    digitalWrite (pRed, LOW);
    digitalWrite (pGreen, HIGH);
    currentTime = millis();
    while (millis()-currentTime < crossTime){
      if (millis()-currentTime > blinkCrossTime){
        digitalWrite (pGreen, LOW);
        delay (500);
        digitalWrite (pGreen, HIGH);
        delay (500);
      }
    }
    digitalWrite (pGreen, LOW);
    digitalWrite (pRed, HIGH);
    digitalWrite (red, LOW);
    digitalWrite (green, HIGH);
    currentTime = millis();
    parameter = 0;
  }
}
