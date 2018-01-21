const int sensorPin = A0;    // pin waar de lichtsensor aan verbonden is
const int ledPin = 9;        // pin waar de led aan verbonden is

int sensorValue = 0;         // waarde
int sensorMin = 1023;        // minimum 
int sensorMax = 0;           // maximum 


void setup() {
  // zet de led op de waarde waarmee ik upload. LET OP upload in donker!!
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  
  while (millis() < 3000) {
    sensorValue = analogRead(sensorPin);

    //  maximum van de sensorwaarde
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // minimum van de sensorvalue
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }


  digitalWrite(13, LOW);
}

void loop() {
  // lees de waarde van de sensor
  sensorValue = analogRead(sensorPin);


  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);


  sensorValue = constrain(sensorValue, 0, 255);

  // fade van de led als de waardes afnemen
  analogWrite(ledPin, sensorValue);
}

