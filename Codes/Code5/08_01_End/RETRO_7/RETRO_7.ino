/*

 RETRO
 Space invader Game
 Author: Red Team Leader
   
   The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// Sketch settings
const char LASER_SYMBOL = '^';

// include the library code:
#include <LiquidCrystal.h>

// Invader string
String invaders;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Current laser position
int laserColumn;

// Timer variables
unsigned long timerStart;
unsigned long timerInterval;
unsigned long currentTime;

// Button debounce variables
int currentReading;
int newReading;

// Edge detection variable
int previousReading;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Initilize laser position
  laserColumn = 0;

  // Initialize invaders
  invaders = "** * ** * **  **";

  // Display invaders
  lcd.setCursor(0, 0);
  lcd.print(invaders);

  // Setup laser button
  pinMode(7, INPUT_PULLUP);

  // Initialize timer
  timerStart = millis();
  timerInterval = 250;

  // Initialize debouncing
  currentReading = digitalRead(7);
  
}

void loop() {

  currentTime = millis();
  if((currentTime-timerStart) > timerInterval) {

    // Reset timer
    timerStart = currentTime;
  
    // Erase the old frame
    lcd.setCursor(laserColumn, 1);
    lcd.print(' ');
    
    // Calculate new frame
    laserColumn = laserColumn + 1;
  
    // Limit the laser column
    if (laserColumn > 15) {
      laserColumn = 0;
    }
    
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(laserColumn, 1);
    lcd.print(LASER_SYMBOL);
  }

  // Save the current button reading
  previousReading = currentReading;

  // Debounce the button
  currentReading = debounce(7, currentReading, 4);

  // Check the button and zap invaders
  if ((previousReading == HIGH) && (currentReading == LOW)) {
    lcd.setCursor(laserColumn, 0);
    lcd.print(' ');
  }

}

int debounce(int pin, int pinState, int interval) {
  int newValue;
  newValue = digitalRead(pin);
  if (newValue != pinState) {
    delay(interval);
    newValue = digitalRead(pin);
    if (newValue != pinState) {
      pinState = newValue;
    }
  }
  return pinState;
}
