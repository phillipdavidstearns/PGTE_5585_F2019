#define BUTTON_PIN 4
#define LED1_PIN 5
#define LED2_PIN 6
#define LED3_PIN 7


boolean led1_state, button_last_read;
unsigned long button_last_pressed, button_last_released;
int debounce, button_state, button_last_state, pressed_delay, released_delay;

void setup() {

  led1_state = LOW;
  button_last_read = 0;
  button_last_pressed = 0;
  button_last_released = 0;
  debounce = 50;
  pressed_delay = 250;
  released_delay = 250;

  pinMode( BUTTON_PIN, INPUT_PULLUP ); // INPUT_PULLUP uses a built in pullup resistor
  pinMode( LED1_PIN, OUTPUT );
  pinMode( LED2_PIN, OUTPUT );
  pinMode( LED3_PIN, OUTPUT );

}

void loop() {
  boolean button_current_read = digitalRead( BUTTON_PIN );
  unsigned long current_time = millis();

  if (button_last_read == 1 && button_current_read == 0) { // button pressed
    if (current_time - button_last_pressed > (unsigned long) debounce) {
      button_last_pressed = current_time;
    }
  }

  if (current_time - button_last_pressed < (unsigned long) pressed_delay ) {
    digitalWrite( LED1_PIN, 1);
  } else {
    digitalWrite( LED1_PIN, 0);
  }

  //////////////////

  if (button_last_read == 0 && button_current_read == 1) { // button released
    if (current_time - button_last_released > (unsigned long) debounce) {
      button_last_released = current_time;
    }
  }

  if (current_time - button_last_released < (unsigned long) released_delay ) {
    digitalWrite( LED3_PIN, 1);
  } else {
    digitalWrite( LED3_PIN, 0);
  }

  //////////////////

  if ( button_last_read == 0 && button_current_read == 0 ) { // button held

    digitalWrite( LED2_PIN, 1);
  } else {
    digitalWrite( LED2_PIN, 0);
  }


  button_last_read = button_current_read;
}
