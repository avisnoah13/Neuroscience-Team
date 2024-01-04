#include <RBDdimmer.h>  //dimmer library from RobotyDYN


#define outputPin  12 
#define zerocross  2
#define ssrPin 5
int power_level = 0;
int ssr_state = 0;

dimmerLamp dimmer(outputPin);


void setup() { //setup code taken from RobotDYN library examples
  pinMode(ssrPin, OUTPUT); //initializes the pin for the solid state relay
  Serial.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("Dimmer Program is starting...");
}

void loop() {

  if (Serial.available())
    {
        String python_data = Serial.readString(); 
        Serial.print("Received Value: ");
        Serial.println(python_data);

        String power_string = python_data.substring(0,3); // the first three digits of the integer from python are a 3 digit percentage value for the dimmer
        String ssr_string = python_data.substring(3); // the last digit is 0 or 1 to represent on or off for the relay

        power_level = power_string.toInt();
        ssr_state = ssr_string.toInt();

        if(power_level >= 0 && power_level <= 100){ // check to make sure power_level is a valid percent number
          dimmer.setPower(power_level);           //Use the dimmer library to set the power of the dimmer with the data received from python
        }
        else {Serial.println("Not a valid input");}

        digitalWrite(ssrPin, ssr_state);        //Switch the Relay on and off based on data received form python
    }

}