#include <Stepper.h>
int SPU = 2048;                 // steps per umdrehung
Stepper Motor(SPU, 7, 5, 4, 6); // in1=6, in2=5, in3=4, in4=7
void setup()
{
    Motor.setSpeed(10); // umdrehungen pro min
}
void loop()
{
    Motor.step(2048); // ganze drehung
    delay(1000);      // delay
    Motor.step(-2048);
    delay(1000);
}
