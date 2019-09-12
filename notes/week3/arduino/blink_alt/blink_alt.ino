unsigned long last_time; // **last time**
unsigned long wait_time; // **wait_time**
boolean led_state;

void setup(){
  last_time = 0;
  wait_time = 1000;
  led_state = false;
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  unsigned long current_time = millis(); // **current time** read at the start of the loop
  if( current_time - last_time > wait_time ){ // we then compare the elapsed time with the duration
    toggleLED();
    last_time = current_time; // store the current time as the last time the event was triggered
  }
}

void toggleLED(){
  digitalWrite(LED_BUILTIN, led_state); led_state = !led_state;
}
