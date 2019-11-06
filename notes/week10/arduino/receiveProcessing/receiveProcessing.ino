/*
    receiveProcessing echos serial characters back to the sender (Processing)
*/

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() { // free runnin'!!!
}

void serialEvent() {
  //Serial.read() reads in the next byte in the UART buffer
  //It must be cast as a char() to be sent back
  //note that we are using Serial.print() and not Serial.println()
  //Serial.println() will add an invisible new line character
  Serial.print( char( Serial.read() ) ); // what we receive, we send back!
}
