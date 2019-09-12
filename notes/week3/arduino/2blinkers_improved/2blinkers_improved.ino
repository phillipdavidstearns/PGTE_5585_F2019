/*
   2 blinkers demonstrates the use of arrays, for loops, conditionals and a simple timing mechanism
*/

// definitions
#define QTY_LEDS 2

// variables are declared
unsigned long delay_times[] = { 250, 300 };
int led_pins[] = { 12, 13 };
unsigned long last_times[QTY_LEDS];
boolean led_states[QTY_LEDS];

// setup() is run once, variables and IO are initialized
void setup() {
  for (int i = 0 ; i < QTY_LEDS ; i++) {
    last_times[i] = 0;
    led_states[i] = false;
    pinMode(led_pins[i], OUTPUT);
  }
}

// loop is run continuously
void loop() {
  long current_time = millis();
  for (int i = 0 ; i < QTY_LEDS ; i++) {
    if ( current_time - last_times[i] > delay_times[i] ) {
      digitalWrite(led_pins[i], led_states[i]);
      led_states[i] = !led_states[i];
      last_times[i] = current_time;
    }
  }
}
