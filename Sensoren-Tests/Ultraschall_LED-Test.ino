int trigger = 7;    // port für trigger
int echo = 6;       // port echo
int LED = 12;       // port LED
int entfernung = 0; // variable entfernung wert 0
int dauer = 0;      // variable dauer wert 0

void setup()
{
    Serial.begin(9600);
    pinMode(trigger, OUTPUT); // trigger output
    pinMode(echo, INPUT);     // echo interrupt
    pinMode(12, OUTPUT);      // LED output
}

void loop()
{
    digitalWrite(trigger, LOW);
    delay(5);
    digitalWrite(trigger, HIGH);
    delay(10);
    digitalWrite(trigger, LOW);
    dauer = pulseIn(echo, HIGH);        // entfernungsmessung durch zeitabstände
    entfernung = (dauer / 2) * 0.03432; // dauer/2 (hin und rückweg)     *schallgeschwindigkeit in cm/s

    if (entfernung >= 500 || entfernung <= 0)
    {
        Serial.println("Kein Messwert");
    }

    else
    {
        Serial.print(entfernung);
    }

    if (entfernung <= 40)
    {
        digitalWrite(LED, HIGH);
        delay(entfernung * 3);
        digitalWrite(LED, LOW);
        delay(entfernung * 3);
    }
}