void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinRead = analogRead(A0);
  if(pinRead < 500){
    pinRead = 499 - pinRead;
    pinRead = map(pinRead, 0, 499, 0, 255);
    analogWrite(3, pinRead);
    analogWrite(6, 0);
  }
  else if(pinRead >= 500 && pinRead < 525){
    analogWrite(3, 0);
    analogWrite(6, 0);
  }
  else{
    pinRead = map(pinRead, 525, 1024, 0, 255);
    analogWrite(3, 0);
    analogWrite(6, pinRead);
  }
  delay(15);
}
