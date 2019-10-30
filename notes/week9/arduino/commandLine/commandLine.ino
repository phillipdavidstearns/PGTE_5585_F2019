/*
   Do stuff when an incoming serial command matches

   NOTE: Make sure No line ending is selected

*/

unsigned long currentTime = 0, lastTime = 0, period = 250;
boolean LEDState = false, blinking = false;
int count = 0, blinks = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  blinkLED();
}

void serialEvent() {
  //statements
  String command = Serial.readString();
  if ( command == "ping") { // if else ladder to read and interpret commands
    Serial.println("pong");
  } else if ( command == "help") {
    Serial.println();
    Serial.println("---switchFunction help menu---");
    Serial.println("ping      responds with \"pong\" ");
    Serial.println("help      prints this menu");
    Serial.println("special   makes the LED blink 5 times");
    Serial.println();
  } else if ( command == "special") {
    Serial.print("Blinking built-in LED ");
    Serial.print(blinks);
    Serial.println(" times...");
    blinking = true; // set blinking flag
  } else {
    Serial.println("Unrecognized command. Enter \"help\" for list of commands");
  }
}

void blinkLED() {
  currentTime = millis(); // staore current time
  if (blinking && currentTime - lastTime > 250) { //if it's time, do the thing
    LEDState = !LEDState; // toggle LED
    lastTime = currentTime; // store last time we toggled
    if (count < 2 * blinks) { // 2 toggles per cycle
      count++;
    } else {
      count = 0;
      blinking = false; // clear blinking flag
      LEDState = 0; // turn off LED
      Serial.println("Blinking done.");
    }
  }
  digitalWrite(LED_BUILTIN, LEDState);
}
