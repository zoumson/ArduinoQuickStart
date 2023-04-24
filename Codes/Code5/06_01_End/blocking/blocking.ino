void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(13, digitalRead(7));
  //delay(2000);
  
}
