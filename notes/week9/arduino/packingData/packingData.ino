/*
 *  packingData demonstrates how to send 8-bit analog data over serial
 *  via the char datatype
 *  
 *  by Phillip Stearns
 */

void setup() {
  Serial.begin(9600); // start serial
}

void loop() {
  delay(250); // don't spam the console
  char valueToSend = char(map(analogRead(A0),0,1023,0,255)); //convert from 0-1023 to char (0-255)
  Serial.print(valueToSend); // send it out
  Serial.print(" = ");
  Serial.println(byte(valueToSend));
}
