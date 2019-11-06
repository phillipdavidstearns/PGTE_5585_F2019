/*
    stringProcessing accepts serial strings from (Processing)
*/

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  checkUART(); // serialEvent stopped becoming useful
}

void checkUART() {
  while (Serial.available() > 0 ) { // if there's stuff in the UART buffer
    String message = Serial.readStringUntil('\n'); // read strings until new line
    message.replace("\n", ""); // strip new line off the message
    if (message.equals("Ping")) {
      Serial.println("Pong");
    } else if (message.equals("Analog 0")) {
      Serial.println(analogRead(A0));
    } else {
      Serial.print("Unrecognized Command: \"");
      Serial.print(message);
      Serial.println("\"");
    }
  }
}
