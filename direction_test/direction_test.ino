#include <ArduinoRobot.h>

void setup(){
  Robot.begin();
  Robot.beginTFT();//Initialize the TFT module
}

void loop(){
  Robot.text("Hello World",0,0,true);
  delay(2000);

  Robot.text("Hello World",0,0,false);//It's necessary to erase the old text, for showing new text
  Robot.text("I am a robot",0,0,true);
  delay(3000);

  Robot.text("I am a robot",0,0,false);
}
