//SAMENWERKING MET NADINE, SOPHIE & NOURA

#include <Servo.h>
#define PIN_LED 11
#define PIN_LED2 12

#define STEP_FORWARD 10// doen we voor servo
#define STEP_BACK -10

int ledState = LOW;
long ledChangeTime = 0L; // wanneer is die led van stand veranderd 

int servoState = STEP_FORWARD;
int servoPos = 0;
long servoStepTime = 0l; //tijd -- 0LONG

Servo myServo;
  
volatile byte state = HIGH;                                                 // nodig voor interupt. variabele voor button status
//_____________________________________________________________________

void setup() {
Serial.begin(9600);  //open de seriële verbinding
myServo.attach(9);
attachInterrupt(digitalPinToInterrupt(3),buttonISR, CHANGE);               // nodig voor interupt, linkt de interupt aan de button

pinMode(11, OUTPUT);
pinMode (12, OUTPUT);
pinMode(A0, INPUT);
pinMode(3, INPUT_PULLUP);                                                  // nodig voor interupt, geeft aan wat pin 2 is


}

void loop() {
int value = analogRead(A0);
Serial.print("value = ");
Serial.println(value);

digitalWrite (PIN_LED2, state); //zorgt dat het ledje op 12 aan of uit gaat



long currentTimeMS = millis(); // wat is de huidige tijd?
if (currentTimeMS - ledChangeTime > 500){ // als huidige tijd - ledchangetime hoger is dan 500 ....
  if (ledState == LOW){
    ledState = HIGH;
  }else {
    ledState = LOW;
  }
  digitalWrite(PIN_LED, ledState); //nieuwe status LED
  ledChangeTime = currentTimeMS; // wanneer we voor het laatst iets veranderd hebben
}

if (currentTimeMS - servoStepTime > 15){
  myServo.write(servoPos);
  servoStepTime = currentTimeMS;
  if (servoState == STEP_FORWARD){
    servoPos += 10;
  }else {
    servoPos -= 10;
  }

 if (servoPos > 180){
  servoPos = 180;
  servoState = STEP_BACK;
 }else if(servoPos < 0){
  servoPos = 0;
  servoState = STEP_FORWARD;
 }
}
} // einde void loop

void buttonISR(){

  state = !state;
}
