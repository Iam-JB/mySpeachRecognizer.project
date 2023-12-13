#include "DisplayMyVoice.h"
#define NO_CMD -1
using namespace std ;

void DisplayMyVoice::init(){
  DisplayMyVoice* DMV = new DisplayMyVoice() ;
  LED->setupMatrix(); // il faut une instance de matrice
}

void DisplayMyVoice::run() {
  
  try {
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
  catch (int err) {
    if (err == NO_CMD) {
      Serial.print("Capteur vocal non disponible");
    }
  }
  
}
