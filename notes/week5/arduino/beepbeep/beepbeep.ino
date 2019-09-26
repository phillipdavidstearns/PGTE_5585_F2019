/*
   beepbeep.ino

   a sketch to demonstrate using analog input to control the
   frequency of a pulse stream

   by Phillip David Stearns for Physical Computing I PGTE 5585 F2019
*/

//////////////////////////////////////////////////////////////////
// definitions

#define BUTTON_PIN 4
#define SPEAKER_PIN 5
#define SENSOR_PIN A0

//////////////////////////////////////////////////////////////////
// variables

const int debounce = 20; //ms interval we poll the BUTTON_PIN
unsigned long last_button_time, last_pulse_time, current_time; // places to keep track of time
boolean button_read, last_button_read; // track the button states
int pulse, frequency; // duration of the pulse and placeholder for the frequency
float delay_min, delay_max; //the frequency range of the pulse stream

//////////////////////////////////////////////////////////////////
// setup()

void setup() {

  last_button_time = 0;
  last_pulse_time = 0;
  current_time = 0;
  button_read = HIGH;
  last_button_read = HIGH;
  frequency = 0;
  pulse = 1;
  delay_min = 2;
  delay_max = 20;
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(SPEAKER_PIN, OUTPUT);

}

//////////////////////////////////////////////////////////////////
// loop()

void loop() {
  current_time = millis(); // global, all functions can use
  if (readButton()) makeSound(); //if the function readButton() returns true, makeSound()
  updatePulse(); // runs each loop
}

//////////////////////////////////////////////////////////////////
// readButton()

boolean readButton() {
  // debounce!
  boolean button_state;
  if (current_time - last_button_time > debounce) { // if it's time to read the button...
    button_read = digitalRead(BUTTON_PIN); // store its state
    last_button_time = current_time; // reset debounce timer
  }

  if (last_button_read == LOW && button_read == LOW) { // only true if held
    button_state = true;
  } else {
    button_state = false;
  }

  last_button_read = button_read; // store button reading for future comparison
  return button_state;
  
}

//////////////////////////////////////////////////////////////////
// makeSound()

void makeSound() {
  // timer for the pulse stream
  if (current_time - last_pulse_time > frequency ) {
    frequency = updateFrequency();
    last_pulse_time = current_time; // updates the variable for the pulse timer
  }
}

//////////////////////////////////////////////////////////////////
// updateFrequency()

int updateFrequency() {
  // updates the frequency of the pulse stream
  return int(delay_min + float(analogRead(SENSOR_PIN)) / 1023.0 * (delay_max - delay_min));
}

//////////////////////////////////////////////////////////////////
// updatePulse()

void updatePulse() {
  // timer for a single pulse duration
  if (current_time - last_pulse_time < pulse) {
    digitalWrite(SPEAKER_PIN, HIGH);
  } else {
    digitalWrite(SPEAKER_PIN, LOW);
  }
}
