/**
 * stringDuplex sends and receives strings over serial
 * A version of 
 * Serial Duplex 
 * by Tom Igoe
 *
 * Modified by Phillip David Stearns
 *
 */


import processing.serial.*;

Serial myPort;      // The serial port
String ping = "Ping";  // Variable to hold keystoke values
String pong = "";    // Incoming serial data
String message = "";
String lastMessage = "";

void setup() {
  size(400, 300);
  // create a font with the third font available to the system:
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);

  // List all the available serial ports:
  printArray(Serial.list());

  // I know that the 3rd port in the serial list on my mac
  // is where my Arduino typically shows up, so I open Serial.list()[2].
  // Open whatever port is the one you're using.
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(0);
  text("Last Received: " + pong, 10, 130);
  text("Last Sent: " + lastMessage, 10, 100);
  text("Next Message: " + message, 10, 160);

  while (myPort.available() > 0) {
    pong = myPort.readStringUntil('\n');   
    //if (pong != null) print(pong);
  }
}

void keyPressed() {
  // println(byte(key));
  if ( key == RETURN || key == ENTER ) { // send the message
    myPort.write(message+char(10));
    lastMessage=message;
    message = "";
  } else if (key == BACKSPACE || key == DELETE) { // delete last character
    if (message.length() > 0)
      message = message.substring( 0, message.length()-1 );
  } else if ( key!= CODED ) {
    if (message.length() < 128) message+=key;
  } else if ( keyCode == UP ) {
    message=lastMessage;
  }
}
