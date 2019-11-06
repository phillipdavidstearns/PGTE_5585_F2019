/*

basicProcessing
by Phillip Stearns

A "Hello World" in Arduino is a blinking LED.
In Processing its a circle...

*/

void setup(){ // runs once before the draw() loop
  size(500,500); // must always go first, set the draw window dims
}

void draw(){ // executes onces every frameRate times/second
  background(0); // set background to black
  noStroke(); // set stroke to invisible/none
  fill(255); // set fill color to white
  circle(width/2,height/2, mouseX); // width, height, and mouseX are built in vars
}
