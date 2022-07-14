int trigger=7;                              
int echo=6;
int LED=12;
int entfernung=0;
int dauer=0;

void setup()
{
Serial.begin (9600);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(12, OUTPUT);
}

void loop()
{
digitalWrite(trigger, LOW);
delay(5);
digitalWrite(trigger, HIGH);
delay(10);
digitalWrite(trigger, LOW);
dauer = pulseIn(echo, HIGH);
entfernung = (dauer/2) * 0.03432;


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
delay(entfernung*3);
digitalWrite(LED, LOW);
delay(entfernung*3);
}
}