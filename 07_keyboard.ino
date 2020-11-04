const int pinIn = A0;
const int pinOut = 8;

int input = 0;

// Note frequencies (in Hz)
int notes[] = {
    262,  // C
    294,  // D
    330,  // E
    349}; // F

void setup()
{
    pinMode(pinOut, OUTPUT);
    //Serial.begin(9600);
}

void loop()
{
    input = analogRead(pinIn);

    //Serial.println(input);
    //delay(50);

    // Input calibration:
    //  Button #1: 1023
    //  Button #2: (990, 101)
    //  Button #3: (490, 550)
    //  Button #4: (3, 50)

    if (input == 1023)
    {
        tone(pinOut, notes[0]);
    }
    else if (input > 990 and input < 1010)
    {
        tone(pinOut, notes[1]);
    }
    else if (input > 490 and input < 550)
    {
        tone(pinOut, notes[2]);
    }
    else if (input > 3 and input < 50)
    {
        tone(pinOut, notes[3]);
    }
    else
    {
        noTone(pinOut);
    }
}