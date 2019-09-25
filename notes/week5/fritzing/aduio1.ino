/*
 * beepbeeo.ino
 * 
 * a sketch to demonstrate using analog input to control the
 * frequency of a pulse stream
 * 
 * by Phillip David Stearns for Physical Computing I PGTE 5585 F2019
 */
 
#define BUTTON_PIN 4
#define SPEAKER_PIN 5
#define SENSOR_PIN A0

const int debounce = 20; //ms interval we poll the BUTTON_PIN
unsigned long last_button_time, last_pulse_time, current_time; // places to keep track of time
boolean button_read, last_button_read; //
int pulse, frequency; // duration of the pulse and the center frequency of the pulse stream

void setup() {

  last_button_time = 0;
  last_pulse_time = 0;
  current_time = 0;
  button_read = HIGH;
  last_button_read = HIGH;
  pulse = 1;
  frequency = 2;
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(SPEAKER_PIN, OUTPUT);

}

void loop() {
  current_time = millis(); // because it's global all other functions can access
  if (readButton()) makeSound(); //if the function readButton() returns true, makeSound()
  updatePulse(); // runs each loop
}

boolean readButton() {
  // debounce!
  if (current_time - last_button_time > debounce) { // if it's time to read the button...
    button_read = digitalRead(BUTTON_PIN); // store its state
    last_button_read = button_read; // store button reading for future comparison
    last_button_time = current_time; // reset debounce timer
  }
  
  if (last_button_read == LOW && button_read == LOW) { // only true if held
    return true;
  } else {
    return false;
  }
  
}

void makeSound() {
  // timer for the pulse stream
  if (current_time - last_pulse_time > frequency) {
    updateFrequency(); // updates the frequency of the pulse stream
    last_pulse_time = current_time; // updates the variable for the pulse timer
  }
}

void updateFrequency() {
  frequency = int(2 * float(analogRead(SENSOR_PIN ))  /  1023.0);
}

void updatePulse() {
  // timer for a single pulse duration
  if (current_time - last_pulse_time < pulse) {
    digitalWrite(SPEAKER_PIN, HIGH);
  } else {
    digitalWrite(SPEAKER_PIN, LOW);
  }
}
