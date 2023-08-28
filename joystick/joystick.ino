// Pin definitions
#define XPIN A0
#define YPIN A1
#define BUTTON1 2
#define BUTTON2 4
#define BUTTON3 7

// Enum for the joystick state - player must return joystick back to CENTRE before logging another action
enum JoystickState {
  CENTRE,
  MOVING
};

// Initialise default state
JoystickState currentState = CENTRE;
JoystickState prevState = CENTRE;

void setup() { 
  Serial.begin(9600); // Initialise Baud Rate: Lets you output to serial monitor
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(BUTTON1, INPUT);  
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
}

void loop() {
  int xVal = analogRead(XPIN);
  int yVal = analogRead(YPIN);
  int b1 = digitalRead(BUTTON1);
  int b2 = digitalRead(BUTTON2);
  int b3 = digitalRead(BUTTON3);

  prevState = currentState;

  if (xVal < 200 || xVal > 900 || yVal < 200 || yVal > 900) {
    // If joystick is off centre, then we are moving
    currentState = MOVING;
  } else {
    currentState = CENTRE;
  }

  // Only allow actions if previous state has been returned to centre.
  if (prevState == CENTRE && currentState == MOVING) {
    if (xVal < 200) {Serial.write('A');}      // Move left
    else if (xVal > 900) {Serial.write('D');} // Move right
    else if (yVal > 900) {Serial.write('S');} // Move downward
    else if (yVal < 200) {Serial.write('W');} // Move upward
  }

  /*Additional controls if required. Debounce the buttons with delay */
  if (b1 == HIGH) {Serial.write('B'); delay(200);} // Leftmost button
  if (b2 == HIGH) {Serial.write('Z'); delay(200);} // Middle button 
  if (b3 == HIGH) {Serial.write('U'); delay(200);} // Rightmost button
  // delay(10);
}


