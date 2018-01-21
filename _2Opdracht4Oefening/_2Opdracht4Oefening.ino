#include <Servo.h>

#define PIN_LED 11

#define STEP_FORWARD 10
#define STEP_BACK -10

Servo myServo;

int ledState = LOW;
long ledChangeTime = 0L;

int servoState = STEP_FORWARD;
int servoPos = 0;
long servoStepTime = 0L;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);

  pinMode(PIN_LED, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
 int value = analogRead(A0);
 Serial.print("value = ");
 Serial.println(value);

 long currentTimeMS = millis();
 if (currentTimeMS - ledChangeTime > 500){
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(PIN_LED, ledState);
  ledChangeTime = currentTimeMS;
 }

 if (currentTimeMS - servoStepTime > 100) {
  myServo.write(servoPos);
  servoStepTime = currentTimeMS;
  if (servoState == STEP_FORWARD) {
    servoPos += 10;
  } else {
    servoPos -=10;
  }

  if (servoPos > 180) {
    servoPos = 180;
    servoState = STEP_BACK;
  } else if (servoPos < 0) {
    servoPos = 0;
    servoState = STEP_FORWARD;
  }
 }

 for (int pos = 0; pos <= 180; pos+=10) {
  myServo.write(pos);
  delay(100);
 }
 
 for (int pos = 180; pos > 0; pos-=10) {
  myServo.write(pos);
  delay(100);
 }
}
