int LED=13; //identify pin 13
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT); // initialize digital pin LED as an output
Serial.begin(9600);  // initialize serial communication at 9600 bits per seconds
}

void loop() {
  // put your main code here, to run repeatedly:
  counter=counter+1; // adding one everytime it loops
  Serial.print("Blink Number # "); // Printing using serial monitor
  Serial.println(counter);         // printing the value of the variable counter using serial montiro
digitalWrite(LED,HIGH);// turn ON the LED
delay(1000);          // wait for 1 second
digitalWrite(LED,LOW); // Turn OFF the LED
delay(500);           // wait for half a second
}
