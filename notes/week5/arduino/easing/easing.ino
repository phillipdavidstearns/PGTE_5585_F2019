#define LED_PIN 5

float currentValue;
float targetValue;
float easingAmount;

void setup(){
  currentValue = 0;
  targetValue = 255;
  easingAmount = .125;
  Serial.begin(9600);
}

void loop(){
  currentValue += easingAmount * ( targetValue - currentValue );
  Serial.print("currentValue: ");
  Serial.print(currentValue);
  Serial.print("\t targetValue: ");
  Serial.println(targetValue);
  analogWrite(LED_PIN, (int) currentValue);
  delay(250);
}
