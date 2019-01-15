#include <RBDdimmerESP8266.h>//

#define outPin  12 // pin for dimming don't use pins A0, D3(GPIO00), D4(GPIO2) 
#define ZCPin   14 // Zero-Cross don't use pins A0, D0(GPIO16), D3(GPIO00), D4(GPIO2)

dimmerLampESP8266 dimmer(outPin, ZCPin); //initialase port for dimmer 

void setup() {
  Serial.begin(9600);
  dimmer.begin(TOGGLE_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("--- Toggle dimmer example ---");
  dimmer.toggleSettings(0, 100); //Name.toggleSettings(MIN, MAX);
  dimmer.setState(ON); // state: dimmer1.setState(ON/OFF);
  pinMode(14, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:

}
