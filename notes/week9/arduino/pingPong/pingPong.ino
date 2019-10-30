/*
 * Do stuff when an incoming serial message matches 
 * 
 * NOTE: Make sure No line ending is selected
 * 
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent() {
  //statements
  if ( Serial.readString()=="ping" ){
    Serial.println("pong");
  } else {
    Serial.println("...");
  }
    
}
