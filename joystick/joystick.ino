#define XPIN A0
#define YPIN A1
#define SW_DROP 2
#define ROTATE_L 4
#define ROTATE_R 7

void setup() { 
  Serial.begin(9600); // Initialise Baud Rate: Lets you output to serial monitor
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(SW_DROP, INPUT);  
  pinMode(ROTATE_L, INPUT);
  pinMode(ROTATE_R, INPUT);
}

void loop() {
  int xVal = analogRead(XPIN);
  int yVal = analogRead(YPIN);
  int swDropVal = digitalRead(SW_DROP);
  int rotateL = digitalRead(ROTATE_L);
  int rotateR = digitalRead(ROTATE_R);
  delay(50); // Add a small delay for debounce

  if (xVal < 200) {Serial.write('A');}      // Move left
  else if (xVal > 900) {Serial.write('D');} // Move right
  else if (yVal > 900) {Serial.write('S');} // Move downward
  else if (swDropVal == HIGH) {Serial.write('B');}   // Hard drop the block
  else if (rotateL == HIGH) {Serial.write('Z');}  // Rotate block left
  else if (rotateR == HIGH) {Serial.write('U');} // Rotate block right
  delay(200);
}


