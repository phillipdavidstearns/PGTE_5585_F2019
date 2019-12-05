unsigned long currentTime = 0;
unsigned long sendIntervals[6] = { 872, 2743, 1517, 2001, 1750, 808 };
unsigned long lastSentTimes[6] = { 0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
}

void loop() {
  currentTime = millis();
  for (int i = 0 ; i < 6; ++i) {
    if (currentTime - lastSentTimes[i] >= sendIntervals[i]) {
      Serial.println(theMessage(i));
      lastSentTimes[i] = currentTime;
    }
  }
}

String theMessage(int _case){
  switch(_case){
    case 0:
    return String("Hello!");
    break;
    case 1:
    return String("This");
    break;
    case 2:
    return String("is ");
    break;
    case 3:
    return String("a");
    break;
    case 4:
    return String("Hello");
    break;
    case 5:
    return String("world!");
    break;
  }
}
