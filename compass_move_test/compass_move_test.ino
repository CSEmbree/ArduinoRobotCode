

// include the robot library
#include <ArduinoRobot.h>

int speedLeft;
int speedRight;
int compassValue;
int direc = 180;  //Direction the robot is heading

void setup() {
  // initialize the modules
  Robot.begin();
  Robot.beginTFT(); //init screen
  Robot.beginSD(); //init SD card
  //Robot.displayLogos();
  Robot.beginSpeaker();//Initialize the sound module
}

void loop() { 
  // read the compass orientation
  compassValue = Robot.compassRead();

  // how many degrees are we off
  int diff = compassValue-direc;

  // modify degress 
  if(diff > 180)
    diff = -360+diff;
  else if(diff < -180)
    diff = 360+diff;

  // Make the robot turn to its proper orientation
  diff = map(diff, -180, 180, -255, 255);
  
  if(compassValue>2) { //accurecy to True North within +/- 10 degrees
  
    if(diff > 0) {
      // keep the right wheel spinning, 
      // change the speed of the left wheel 
      speedLeft = 255-diff;
      speedRight = 255;
    } 
    else {
      // keep the right left spinning,
      // change the speed of the left wheel   
      speedLeft = 255;
      speedRight = 255+diff;
    }
    // write out to the motors
    Robot.motorsWrite(speedLeft, speedRight);

    // draw the orientation on the screen
    Robot.drawCompass(compassValue);
  }
  else {
    Robot.motorsStop(); //Fast stop the robot

    char aTinyMelody[] = "8eF-FFga4b.a.g.F.8beee-d2e.1-";// This is what we will play
    Robot.playMelody(aTinyMelody);// Play the melody
    
    delay(5000);
  }
}

