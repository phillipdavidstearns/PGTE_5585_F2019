unsigned long currentTime=0;
unsigned long sendAInterval=1250;
unsigned long sendBInterval=1000;
unsigned long lastAsend=0;
unsigned long lastBsend=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  currentTime = millis();
  if (currentTime - lastAsend >= sendAInterval){
    sendA();
    lastAsend = currentTime;
  }

  if (currentTime - lastBsend >= sendBInterval){
    sendB();
    lastBsend = currentTime;
  }
}

void sendA(){
 Serial.println('A');
}

void sendB(){
 Serial.println('B');
}
