#define yaxis A2
#define xaxis A1
#define tast A0
int yvalue = 0;
int xvalue = 0;
boolean click = true;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    yvalue = analogRead(yaxis);
    Serial.print("y= ");
    Serial.println(yvalue);
    xvalue = analogRead(xaxis);
    Serial.print("x= ");
    Serial.println(xvalue);
    click = analogRead(tast);
    Serial.print("c= ");
    Serial.println(click);
}

// standartwerte sind x=520 y=508 (in Mittelstellung)
// maximmalwerte sind 1023 auf beiden seiten
// taster standartwert 1