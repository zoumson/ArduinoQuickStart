// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
  
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  
  Serial.print("Mapped Sensor Value: ");
  Serial.println(sensorValue);
  
  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
  
  Serial.print("Constrained Sensor Value: ");
  Serial.println(sensorValue);
  
  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  
  delay(1000);
}
