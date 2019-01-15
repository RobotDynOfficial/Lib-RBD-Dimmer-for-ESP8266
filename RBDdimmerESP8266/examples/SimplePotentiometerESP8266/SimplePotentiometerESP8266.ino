#include <RBDdimmerESP8266.h>//

#define outPin  12 // pin for dimming don't use pins A0, D3(GPIO00), D4(GPIO2) 
#define ZCPin   14 // Zero-Cross don't use pins A0, D0(GPIO16), D3(GPIO00), D4(GPIO2)

dimmerLampESP8266 dimmer(outPin, ZCPin); //initialase port for dimmer 

int outVal = 0;

void setup() {
  Serial.begin(9600);
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
}

void loop() 
{
  outVal = map(analogRead(0), 1, 1024, 100, 0); // analogRead(analog_pin), min_analog, max_analog, 100%, 0%);
  Serial.println(outVal); 
  dimmer.setPower(outVal); // name.setPower(0%-100%)
}
