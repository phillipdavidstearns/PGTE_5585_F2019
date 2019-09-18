#define BUTTON_PIN 4
#define LED1_PIN 5
#define LED2_PIN 6
#define LED3_PIN 7


boolean led1_state, button_last_read, button_current_read;
unsigned long button_last_pressed, button_last_released;
int debounce_time, pressed_delay, released_delay;

void setup() {

  led1_state = false;
  button_last_read = 0;
  button_current_read = 0;
  button_last_pressed = 0;
  button_last_released = 0;
  debounce_time = 50;
  pressed_delay = 250;
  released_delay = 250;

  pinMode( BUTTON_PIN, INPUT_PULLUP );
  pinMode( LED1_PIN, OUTPUT );
  pinMode( LED2_PIN, OUTPUT );
  pinMode( LED3_PIN, OUTPUT );

}

void loop() {
  button_current_read = digitalRead( BUTTON_PIN );

  if (buttonIsPressed()) button_last_pressed = debounce(button_last_pressed, debounce_time);
  digitalWrite( LED1_PIN, oneShot( button_last_pressed, pressed_delay ) );

  if (buttonIsReleased()) button_last_released = debounce(button_last_released, debounce_time);
  digitalWrite( LED3_PIN, oneShot( button_last_released, released_delay ) );
  
  digitalWrite( LED2_PIN, buttonIsHeld() );

  button_last_read = button_current_read;
}


boolean oneShot(unsigned long last_trigger, int hold_time) {
  return millis() - last_trigger < (unsigned long) hold_time;
}

boolean buttonIsPressed() {
  return button_last_read == 1 && button_current_read == 0;
}

boolean buttonIsReleased() {
  return button_last_read == 0 && button_current_read == 1;
}

boolean buttonIsHeld() {
  return button_last_read == 0 && button_current_read == 0;
}

unsigned long debounce( unsigned long last_trigger, int debounce_time) {
  unsigned long current_time = millis();
  if (current_time - last_trigger > (unsigned long) debounce_time) {
    return current_time;
  } else {
    return last_trigger;
  }
}
