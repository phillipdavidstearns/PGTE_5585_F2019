/*
  Example sketch to demonstrate using Processing to grab content from an API
 By Phillip Stearns
 Modification of the get example from the HTTP Requests for Processing Library
 
 Download the library if you don't already have it:
 Sketch > Import Library > Add Library...
 */

import http.requests.*; //Sketch > Import Library > HTTP Requests for Processing

GetRequest getCat; // a new HTTP request Object named getCat
String theURL = "https://api.thecatapi.com/api/images/get?type=jpg"; // the cat api!
PImage theCat = createImage(10, 10, RGB); // Object to store the cat image
String filename = "tempCat.jpg"; // name of the temp cat image

void setup() {
  size(10, 10); // temp size for startup
  surface.setResizable(true); // allows us to change the window later in our sketch
  noLoop(); // stops draw() loop, use redraw() to execute draw() "manually"
}

void draw() {
  image(theCat, 0, 0); // draw the cat image
}

void keyPressed() { // executed whenever a key is pressed
  theCat = getCatImage(); // get the cat image
  surface.setSize(theCat.width, theCat.height); // resize the window
  redraw(); // run the draw() loop once
}

PImage getCatImage() { //fetches the image
  getCat = new GetRequest(theURL); // forms the HTTP request
  getCat.send(); // sends it out to the internets
  String raw = getCat.getContent(); // the API returns the raw image data in a string
  byte[] data = new byte[raw.length()]; // we need to convert and store the string as byte[]
  for (int i = 0; i < raw.length(); i++) {
    char c = raw.charAt(i); //get each char in the string
    data[i]=byte(c); //convert it to a byte and store in byte[] data
  }
  saveBytes(filename, data); //save the byte[] as a file
  return loadImage(filename); // load the image and return it
}
