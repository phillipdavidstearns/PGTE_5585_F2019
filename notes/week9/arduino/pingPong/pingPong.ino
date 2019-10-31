/*
 * Do stuff when an incoming serial message matches 
 * 
 * NOTE: Make sure No line ending is selected
 * 
 */

void setup() {
  Serial.begin(9600); // init serial communication
}

void loop() { // runnin free!!!!!
}

void serialEvent() {
  if ( Serial.readString()=="ping" ){ // match the string
    Serial.println("pong"); // do stuff
  } else {
    Serial.println("..."); // otherwise
  }
    
}
