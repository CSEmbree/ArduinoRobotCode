/*
 Motor Test
 
 Just see if the robot can move and turn.
 
 Circuit:
 * Arduino Robot
 
 created 1 May 2013
 by X. Yang
 modified 12 May 2013
 by D. Cuartielles
 
 This example is in the public domain
 */

#include <ArduinoRobot.h>

void setup() {
  // initialize the robot
  Robot.begin();
  Robot.beginSpeaker();//Initialize the sound module
  Robot.beginSD();//Initialize the sd card
  Robot.playFile("pushing_onward.mp3");//Play the original music come with the robot.

}

void loop() {
  Robot.text("Cameron Embree deserves a raise. Wow Cameron how did you get so good?",0,0,true);
  delay(1000);
  Robot.motorsWrite(150,255);   // move forward
  Robot.beep(BEEP_LONG);
  
  Robot.turn(90);
  delay(1000);
  Robot.motorsWrite(150,255);   // move forward
  Robot.beep(BEEP_LONG);
  
  Robot.turn(90);
  delay(1000);
  Robot.motorsWrite(150,255);   // move forward
  Robot.beep(BEEP_LONG);
  
  Robot.turn(90);
  delay(1000);
  Robot.motorsWrite(150,255);   // move forward
  Robot.beep(BEEP_LONG);
}
