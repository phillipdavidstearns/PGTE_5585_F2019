/*
   Debounce_000

   A simple sketch to show how to use timing techniques from last week to debounce a switch

*/

// define pin numbers
#define BUTTON_PIN 2
#define LED1_PIN 13

// delcare variables
unsigned long button_last_read;
int debounce; // time in milliseconds that we want to ignore changes

void setup() {

  button_last_read = 0;
  debounce = 125;

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);

}

void loop() {

  unsigned long current_time = millis();

  // we only read from the button once every 125 ms
  if (current_time - button_last_read > (unsigned long) debounce) {
    button_last_read = current_time;
    digitalWrite(LED1_PIN, digitalRead(BUTTON_PIN)); //this updates the LED to match the button state
  }

}
