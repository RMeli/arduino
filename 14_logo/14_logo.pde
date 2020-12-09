import processing.serial.*;

Serial myPort; // Serial port
PImage logo; // Image

int bgColor = 0; // Background color

void setup()
{
    size(1,1); // Empty window
    surface.setResizable(true);
    colorMode(HSB, 255); // HBS color mode [0, 255]

    // Download Arduino logo
    logo = loadImage("http://arduino.cc/arduino_logo.png");
    
    // Resize to fit logo
    surface.setSize(logo.width,logo.height);

    // Print available ports
    println("Available serial ports:");
    println(Serial.list());

    // Port number
    // To be determined by looking at available ports
    const int portNum = 10;

    // Create new serial connection to port portNum
    myPort = new Serial(this, Serial.list()[portNum], 9600);
}

void draw()
{
    if(myPort.available() > 0){
        // Get background color from Arduino
        bgColor = myPort.read();
        println(bgColor);
    }

    // Set background color and refresh image
    background(bgColor, 255, 255);
    image(logo, 0, 0);
}