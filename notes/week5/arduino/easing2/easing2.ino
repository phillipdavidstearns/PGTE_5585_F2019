//////////////////////////////////////////////////////////////////
// definitions

#define LED_PIN 5
#define BUTTON_PIN 4

//////////////////////////////////////////////////////////////////
// variables

const int debounce = 20;
unsigned int trigger_time, last_button_time, current_time;
boolean button_read, last_button_read, buttonPressed;
float ease_time, progress;

//////////////////////////////////////////////////////////////////
// setup()

void setup() {
  ease_time = 2500.0;
  trigger_time = int(ease_time);
  last_button_time = 0;
  current_time = 0;
  button_read = HIGH;
  last_button_read = HIGH;
  buttonPressed = false;
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

//////////////////////////////////////////////////////////////////
// loop()

void loop() {
  current_time = millis();
  if (buttonIsPressed()) {
    trigger_time = current_time;
    progress = 0;
  }

  progress = (current_time - trigger_time) / ease_time;

  if (progress <= 1) {
    analogWrite(LED_PIN, int(255 * pow(progress, 2)));
  }
}

//////////////////////////////////////////////////////////////////
// buttonIsPressed()

boolean buttonIsPressed() {
  // debounce!
  boolean button_state;
  if (current_time - last_button_time > debounce) { // if it's time to read the button...
    button_read = digitalRead(BUTTON_PIN); // store its state
    last_button_time = current_time; // reset debounce timer
  }

  if (last_button_read == HIGH && button_read == LOW) { // only true if held
    button_state = true;
  } else {
    button_state = false;
  }

  last_button_read = button_read; // store button reading for future comparison
  return button_state;

}
