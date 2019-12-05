void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String theCommand = Serial.println(Serial.readStringUntil('\n'));
    int numSpaces = 0;
    for (int i = 0 ; i < theCommand.length(); ++i) {
      if (theCommand.charAt(i) == ' ') {
        ++numSpaces;
      }
    }
    String decompCommand[numSpaces];
    int spaceIndex == 0;
    int startSub = 0;
    int endSub = 0;
    for (int i = 0 ; i < theCommand.length(); ++i) {
      if (theCommand.charAt(i + 1) == ' ') {
        endSub = i;
        decompCommand[0]=theCommand.substring(startSub, endSub);
        i+=1;
        startSub = i+1;
      }
    }
  }
}
