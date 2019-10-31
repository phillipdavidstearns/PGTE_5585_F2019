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
  if ( command == "help") {
    Serial.println();
    Serial.println("---switchFunction help menu---");
    Serial.println("sensor1      prints value of A0");
    Serial.println("sensor2      prints value of A1");
    Serial.println("read      prints vaule of A0 and A1");
    Serial.println("help      prints this menu");
    Serial.println("blink   makes the LED blink 5 times");
    Serial.println();
  } else if ( command == "sensor1") { // read sensor1
    Serial.print("Value of sensor1: ");
    Serial.println(analogRead(A0));
  } else if ( command == "sensor2") { // read sensor2
    Serial.print("Value of sensor2: ");
    Serial.println(analogRead(A1));
  } else if ( command == "read") { // read both sensor1 and sensor2
    Serial.print("Value of sensor1: ");
    Serial.println(analogRead(A0));
    Serial.print("Value of sensor2: ");
    Serial.println(analogRead(A1));
  } else if ( command == "blink") {
    Serial.print("Blinking built-in LED ");
    Serial.print(blinks);
    Serial.println(" times...");
    blinking = true; // set blinking flag
  } else {
    Serial.println("Unrecognized command. Enter \"help\" for list of commands");
  }
}

void blinkLED() {
  currentTime = millis(); // store current time
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
