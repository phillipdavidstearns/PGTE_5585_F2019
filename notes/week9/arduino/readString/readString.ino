/*
 *  readString echos serial strings back to the sender
 */

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() { // free runnin'!!!
}

void serialEvent() {
  String message = Serial.readString();
  Serial.println( message ); // what we receive, we send back!
}
