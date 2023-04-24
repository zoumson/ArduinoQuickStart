int LED=13; //identify pin 13
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT); // initialize digital pin LED as an output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);// turn ON the LED
delay(1000);          // wait for 1 second
digitalWrite(LED,LOW); // Turn OFF the LED
delay(500);           // wait for half a second
}
