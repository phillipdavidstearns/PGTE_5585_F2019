
boolean lamp;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  lamp=!lamp;
  digitalWrite(LED_BUILTIN, lamp);
}
