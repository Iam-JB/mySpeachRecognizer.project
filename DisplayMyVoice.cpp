#include "DisplayMyVoice.h"
using namespace std ;

char comd ;


// Création d'une instance de reconnaissance de commandes vocales
VoiceRecognizer* VR ;
  
// Création d'une instance de matrice de LED
LEDMatrixController* LED ;

void initialise(){
  VR = new VoiceRecognizer(2,3) ;
  LED = new LEDMatrixController(VR) ;
  
  LED->setupMatrix(); // il faut une instance de matrice
 
}

void run() {

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
