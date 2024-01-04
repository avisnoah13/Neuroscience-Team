#include <RBDdimmer.h>  //dimmer library from RobotyDYN


#define outputPin  12 
#define zerocross  2

dimmerLamp dimmer(outputPin);

int outVal = 0;

void setup() {
  Serial.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("Dimmer Program is starting...");
}

void printSpace(int val)
{
  if ((val / 100) == 0) Serial.print(" ");
  if ((val / 10) == 0) Serial.print(" ");
}

void loop() {

  if (Serial.available())
    {
        String a = Serial.readString(); 
        Serial.print("Received Value: ");
        Serial.println(a);
        int python_int = a.toInt(); // python_int is equal to whatever int was sent over serial from python program
        if(python_int >= 0 && python_int <= 100){ // check to make sure python_int is a valid percent number
          dimmer.setPower(python_int);
        }
        else {Serial.println("Not a valid input");}
    }

}
