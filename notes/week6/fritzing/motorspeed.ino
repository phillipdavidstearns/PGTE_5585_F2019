/*
 * motorspeed
 * 
 * A simple sketch to help demonstrate the used of an
 * NPN transistor and flyback diode to drive a motor
 * with its speed mapped to a potentiometer.
 * 
 * By Phillip Stearns for PGTE_5585_F2019
 * 
 */

#define POT_PIN A0
#define PWM_PIN 3

void setup() {
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // look ma, no variables!
  analogWrite(PWM_PIN, int(255 * analogRead(POT_PIN) / 1023.0));
  delay(20);
}