
const int inPin = A0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.write(map(analogRead(inPin), 0, 1023, 0, 255));
    delay(100);
}