/*
    packingData demonstrates how to send 10-bit analog data over serial
    via the String datatype

    by Phillip Stearns
*/

void setup() {
  Serial.begin(9600); // start serial
}

void loop() {
  checkUART();
}

void checkUART() {
  while (Serial.available() > 0 ) { // if there's stuff in the UART buffer
    String message = Serial.readStringUntil('\n'); // read strings until new line
    message.replace("\n", ""); // strip new line off the message
    if (message.equals("Analog 0")) {
      uint16_t val = analogRead(A0); // 10 bits = 2 chars of 5bits each
      String packedVal = "";
      packedVal += char(val & B11111); // packing first 5 bits
      packedVal += char(val >> 5  & B11111); // packing second 5 bits
      Serial.println(packedVal);
    }
  }
}
