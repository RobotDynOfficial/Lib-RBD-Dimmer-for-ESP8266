#include <RBDdimmerESP8266.h>//

#define outPin  16 // pin for dimming don't use pins A0, D3(GPIO00), D4(GPIO2) 
#define ZCPin   14 // Zero-Cross don't use pins A0, D0(GPIO16), D3(GPIO00), D4(GPIO2)

dimmerLampESP8266 dimmer(outPin, ZCPin); //initialase port for dimmer 

int outVal = 0;

void setup() {
  Serial.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("Dimmer Program is starting...");
  Serial.println("Set value");
}

void printSpace(int val)
{
  if ((val / 100) == 0) Serial.print(" ");
  if ((val / 10) == 0) Serial.print(" ");
}

void loop() {
  int preVal = outVal;

  if (Serial.available())
  {
    int buf = Serial.parseInt();
    if (buf != 0) outVal = buf;
    delay(200);
  }
  dimmer.setPower(outVal); // setPower(0-100%);

  if (preVal != outVal)
  {
    Serial.print("% lampValue -> ");
    printSpace(dimmer.getPower());
    Serial.print(dimmer.getPower());

  }
  delay(50);

}
