#include <RBDdimmerESP8266.h>//

#define outPin  12 // pin for dimming don't use pins A0, D3(GPIO00), D4(GPIO2) 
#define ZCPin   14 // Zero-Cross don't use pins A0, D0(GPIO16), D3(GPIO00), D4(GPIO2)

dimmerLampESP8266 dimmer1(outPin, ZCPin); //initialase port for dimmer 

void setup() {
  Serial.begin(9600);
  dimmer1.begin(NORMAL_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("--- Simple dimmer example ---");
  dimmer1.setPower(50); // setPower(0-100%);
  dimmer1.setState(ON); // setState(ON/OFF);
  pinMode(5, INPUT);
}
void loop() {
  
  if (digitalRead(5) == 1) 
  {
    dimmer1.changeState(); //changes state on the opposite: name.changeState(); 
  }
  Serial.print("Dimmer state: ");
  Serial.println(dimmer1.getState());
  delay(1000);
}
