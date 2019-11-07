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
String response = "";    // Incoming serial data
String message = "";
String lastMessage = "";
int decoded = -1;
void setup() {
  size(500, 250);
  // create a font with the third font available to the system:
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);

  // List all the available serial ports:
  printArray(Serial.list());

  // My Arduino typically shows up at Serial.list()[2].
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(0); // set background to black
  // display the text in the window instead of in the console
  text("Last Received: " + decoded, 10, 130); 
  text("Last Sent: " + lastMessage, 10, 100);
  text("Next Message: " + message, 10, 160);

  while (myPort.available() > 0) { // while there are messages, read them in
    response = myPort.readStringUntil('\n');
    if (response != null && response.length() > 1) {
      while ( response.length() > 2) {
        response = response.substring(0, response.length()-1);
      }
      decoded = int(response.charAt(0) | response.charAt(1) << 5 );
      //println(decoded);
    }
  }
}

void keyPressed() { // let's make it interactive!!!
  // println(byte(key));
  if ( key == RETURN || key == ENTER ) {
    myPort.write(message+char(10));  // send the message
    lastMessage=message; // save as lastMessage
    message = ""; // clear it
  } else if (key == BACKSPACE || key == DELETE) { // delete last character
    if (message.length() > 0)
      message = message.substring( 0, message.length()-1 );
  } else if ( key!= CODED ) { // ignore special keys like SHIFT, CONTROL, UP, etc...
    if (message.length() < 128) message+=key;
  } else if ( keyCode == UP ) { // recall lastMessage
    message=lastMessage;
  }
}
