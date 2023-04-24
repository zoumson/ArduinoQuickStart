const int LED9 = 9;
const int LED7 = 7;

int V = ;
int A = ;
int B = ;

void setup() {
  // initialize pins as output
  pinMode(LED9, OUTPUT);
  pinMode(LED7, OUTPUT);
}

void loop() {
  analogWrite(LED9, V);
  digitalWrite(LED7, HIGH);
  delay(A);
  digitalWrite(LED7, LOW);
  delay(B);
}
