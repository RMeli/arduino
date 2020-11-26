#include <Servo.h>

// Declare servo motor
Servo myServo;

// Input/output pins
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int piezoVal = 0;
int switchVal = 0;

// Min/max values for valid tap
const int minPiezo = 10;
const int maxPiezo = 100;

boolean locked = false;
int numTaps = 0;

void setup()
{
    myServo.attach(9);

    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(switchPin, INPUT);

    Serial.begin(9600);

    digitalWrite(greenLed, HIGH);
    Serial.println("The Box is Unlocked");

    // Move servo to unlocked position
    myServo.write(0);
}

void loop()
{
    if (locked == false) // Unlocked
    {
        switchVal = digitalRead(switchPin);
        if (switchVal == HIGH) // Lock when switch is pressed
        {
            locked = true;

            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
            Serial.println("Box is Locked");
            
            // Move servo to locked position
            myServo.write(90);
            delay(1000); // Wait for servo to rotate
        }
    }
    else
    {
        piezoVal = analogRead(piezo);
        if (numTaps < 3 and piezoVal > 0)
        {
            if (checkValidTap(piezoVal) == true) // Valid tap
            {
                numTaps = numTaps + 1;
            }

            // Print number of missing valid  taps
            Serial.print(3 - numTaps);
            Serial.println(" more taps to go");
        }

        if (numTaps >= 3) // Three (or more) valid taps
        {
            locked = false;

            digitalWrite(greenLed, HIGH);
            digitalWrite(redLed, LOW);
            Serial.println("The box is unlocked");

            // Move servo to unlocked position
            myServo.write(0);
            delay(50);

            // Reset tap counter
            numTaps = 0;
        }
    }
}

// Check if tap is valid
boolean checkValidTap(int value)
{
    if (value > minPiezo and value < maxPiezo)
    {
        // Blink yellow led (feedback for valid tap)
        digitalWrite(yellowLed, HIGH);
        delay(100);
        digitalWrite(yellowLed, LOW);

        Serial.print("Valid Tap of Value ");
        Serial.println(value);
        
        return true;
    }
    else
    {
        Serial.print("Inalid Tap of Value ");
        Serial.println(value);
        
        return false;
    }
}
