const int pinIn = 8;

// 6 LEDs,assumed to be in adjacent digital pins
const int pinOutInit = 2;
const int pinOutEnd = 7;

// Time in milliseconds
// int is a 16-bit integer
// long is a 32-bit integer
// 32-bit integers needed to store large numbers
unsigned long lastTimeOn = 0;
unsigned long elapsedTime = 0;

int switchState = LOW;
int previousSwitchState = LOW;

int led = pinOutInit;
unsigned long timeInterval = 10000; // Millisecond

void setup()
{
    pinMode(pinIn, INPUT);

    for (int pinOut = pinOutInit; pinOut <= pinOutEnd; pinOut++)
    {
        pinMode(pinOut, OUTPUT);
    }
}

void loop()
{
    // Current time in milliseconds
    elapsedTime = millis();

    if (elapsedTime - lastTimeOn > timeInterval)
    {
        digitalWrite(led, HIGH);

        lastTimeOn = elapsedTime;
        led = led + 1; // Go to next (adjacent) pin
        
        if (led == pinOutEnd)
        {
            // TODO: Something fancy
        }
    }

    switchState = digitalRead(pinIn);

    if (switchState != previousSwitchState)
    {
        for (int pinOut = pinOutInit; pinOut <= pinOutEnd; pinOut++)
        {
            digitalWrite(pinOut, LOW);
        }

        led = pinOutInit;
        lastTimeOn = elapsedTime;
    }

    previousSwitchState = switchState;
}