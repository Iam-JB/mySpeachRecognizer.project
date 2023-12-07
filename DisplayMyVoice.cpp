#include "DisplayMyVoice.h"
using namespace std ;

void DisplayMyVoice::init(){
  VR = new VoiceRecognizer(2,3) ;
  LED = new LEDMatrixController(VR) ;
  
  LED->setupMatrix(); // il faut une instance de matrice
 
}

void DisplayMyVoice::run() {

  comd = VR->getCommand() ;

  if (comd == 9) { // Turn_on_the_TV
    LED->Turn_on_TV() ;
  }
  else if (comd == 1) { // Turn_on_the_light
    LED->Turn_on_light() ;
  }
  else if (comd == 20) { // Voice_drawing
    LED->Voice_drawing() ;
  }
  else {
    Serial.print("commande non prise en charge");
  }
}
