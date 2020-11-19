#include <LiquidCrystal.h>

// Cerate a LiquidCrystal object
// Pin 12: enable (EN) pin
// Pin 11: register select (RS) pin
// Pins 5-2: data pins
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Tilt switch
const int switchPin = 6;

int switchState = 0;
int previousSwitchState = 0;

int textSelection = 0;

void setup()
{
    pinMode(switchPin, INPUT);

    // Initialise LCD screen
    // Screen dimensions 16x2
    LCD.begin(16, 2);

    LCD.print("Rocco&Marta say:");
    LCD.setCursor(0, 1);
    LCD.print("Ciao Fra!");
}

void loop()
{
    switchState = digitalRead(switchPin);

    if (switchState != previousSwitchState)
    {
        if (switchState == LOW)
        {
            // Choose random text
            textSelection = random(3);

            // Clear LCD screen and reset cursor to (0, 0)
            LCD.clear();

            //LCD.print("Arduino says:");
            //LCD.setCursor(0, 1);

            // Print text
            switch (textSelection)
            {
            case 0:
                LCD.print("Non mollare!!!");
                LCD.setCursor(0, 1);
                LCD.print("Spacca tutto!");
                break;
            case 1:
                LCD.print("Urbanistica");
                LCD.setCursor(0, 1);
                LCD.print("esame di merda!");
                break;
            case 2:
                LCD.print("Cazzo che sfiga!");
                LCD.setCursor(0, 1);
                LCD.print("Ma vaffanculo...");
                break;
            }
        }
    }

    previousSwitchState = switchState;
}