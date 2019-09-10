/*
 * 2 blinkers demonstrates the limitations of using delay to control timing of multiple outputs
 * Expand to 6 LEDs
 */

// difinitions
#define LED_PIN_1 12

// constants
const int LED_PIN_2 = 13;

// variables are declared
int delay_time_1;
int delay_time_2;
boolean led_state_1;
boolean led_state_2;

// setup() is run once, variables and IO are initialized
void setup() {
  led_state_1 = false;
  led_state_2 = false;
  delay_time_1 = 250;
  delay_time_2 = 250;
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
}

// loop is run continuously
void loop() {
  delay(delay_time_1); 
  digitalWrite(LED_PIN_1, led_state_1);
  led_state_1 = !led_state_1;
  
  delay(delay_time_2); 
  digitalWrite(LED_PIN_2, led_state_2);
  led_state_2 = !led_state_2;
}
