void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String theCommand = Serial.readStringUntil('\n');
    int numSpaces = 0;
    for (uint8_t i = 0 ; i < theCommand.length(); ++i) {
      if (theCommand.charAt(i) == ' ') {
        ++numSpaces;
      }
    }
    int startSub = 0;
    int endSub = 0;
    for (int i = 0 ; i < theCommand.length(); ++i) {
      if (theCommand.charAt(i + 1) == ' ' || i + 1 >= theCommand.length()) {
        endSub = i + 1;
        Serial.println(theCommand.substring(startSub, endSub));
        i = i + 2;
        startSub = i;
      }
    }
  }
}
