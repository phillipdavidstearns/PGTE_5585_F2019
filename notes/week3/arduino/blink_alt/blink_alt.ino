/*
 * blink_alt is an example that shows some other ways of writing a blink program
 */

// constants
//a way of defining constants that doesn't use additional on board memory
#define LED_PIN 3 // any instance of the text "LED_PIN" is replaced with the value 3 at the time the program is compiled

// variables are declared
int delay_time;
boolean led_state;

// setup() is run once, variables and IO are initialized
void setup() {
  led_state = false;
  delay_time = 1000;
  pinMode(LED_PIN, OUTPUT);
}

// loop is run continuously
void loop() {
  delay(delay_time); // puases the loop for a specified number of milliseconds
  digitalWrite(LED_PIN, led_state); // writes the value of led_states to the LED_PIN
  led_state = !led_state; // toggles the value of led_state
}
