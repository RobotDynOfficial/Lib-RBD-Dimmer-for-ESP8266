#include <RBDdimmerESP8266.h>//

#define outPin  12 // pin for dimming don't use pins A0, D3(GPIO00), D4(GPIO2) 
#define ZCPin   14 // Zero-Cross don't use pins A0, D0(GPIO16), D3(GPIO00), D4(GPIO2)

dimmerLampESP8266 dim4(outPin, ZCPin); //initialase port for dimmer 

int buttonRed = 0;

void setup() {
  dim4.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  dim4.setPower(50);
  pinMode(13, INPUT);
}

void loop() {
  buttonRed = digitalRead(13);  
  if (buttonRed == 1)
  {
    delay(10);
    dim4.setState(ON); //name.setState(ON/OFF);
  }  
  if (buttonRed == 0)
  {
    delay(10);
    dim4.setState(OFF); //name.setState(ON/OFF);
  }
}
