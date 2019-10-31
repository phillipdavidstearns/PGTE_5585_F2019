const int qtyLEDs = 8;
int LEDPins[qtyLEDs] = { 4, 5, 6, 7, 8, 9, 10, 11 };

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < qtyLEDs; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }
}

void loop() {
}

void serialEvent() {
  while (Serial.available()) {
    byte data = Serial.read();
    Serial.print("Recieved char: ");
    Serial.print(char(data));
    Serial.print(", ASCII value: ");
    Serial.println(int(data));
    delay(250);
    for (int i = 0; i < qtyLEDs; i++) {
      boolean LEDState = data >> i & 1;
      Serial.print("LED ");
      Serial.print(i);
      Serial.print(", state: ");
      Serial.println(LEDState);
      digitalWrite(LEDPins[i], LEDState);
    }
  }
}
