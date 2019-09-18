/*
   Debounce_000

   A simple sketch to show how to use timing techniques from last week to debounce a switch
   And toggle an LED

*/

// define pin numbers
#define BUTTON_PIN 2
#define LED1_PIN 13

// delcare variables
unsigned long button_last_read;
int debounce; // time in milliseconds that we want to ignore changes
boolean button_state, last_button_state, led_state;

void setup() {

  //initialize variables
  button_last_read = 0;
  debounce = 125;
  button_state = LOW;
  last_button_state = LOW;
  led_state = LOW;

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);

}

void loop() {
  
  // record what time it is
  unsigned long current_time = millis();

  // we only read from the button once every 125 ms
  if (current_time - button_last_read > (unsigned long) debounce) {

    //capture the current button state
    button_state = digitalRead(BUTTON_PIN);

    // if it's HIGH and previously wasn't, toggle the LED
    if ( button_state == HIGH && last_button_state == LOW) {
      led_state = !led_state;
    }

    // update the LED pin
    digitalWrite(LED1_PIN, led_state);

    // store present state for later comparison
    last_button_state = button_state;
    button_last_read = current_time;
    
  }

}
