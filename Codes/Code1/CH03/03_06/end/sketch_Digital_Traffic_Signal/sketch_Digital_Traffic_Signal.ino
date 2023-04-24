
int GreenLed=10;
int YellowLed=11;
int RedLed=12;

void setup() {
  // put your setup code here, to run once:
pinMode(GreenLed,OUTPUT);
pinMode(YellowLed,OUTPUT);
pinMode(RedLed,OUTPUT);

digitalWrite(GreenLed,LOW);
digitalWrite(YellowLed,LOW);
digitalWrite(RedLed,LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//Yield Mode

digitalWrite(GreenLed,LOW);
digitalWrite(YellowLed,HIGH);
digitalWrite(RedLed,LOW);

Serial.println(" Light Mode : Yield ");
delay(1000);

// Go Mode
digitalWrite(GreenLed,HIGH);
digitalWrite(YellowLed,LOW);
digitalWrite(RedLed,LOW);

Serial.println(" Light Mode : Go ");
delay(2000);

// Stop Mode
digitalWrite(GreenLed,LOW);
digitalWrite(YellowLed,LOW);
digitalWrite(RedLed,HIGH);

Serial.println(" Light Mode : STOP ");
delay(2000);
}
