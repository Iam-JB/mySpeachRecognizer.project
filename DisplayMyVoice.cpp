#include "DisplayMyVoice.h"
using namespace std ;

void init(){
  char cmd ;

  // Création d'une instance de reconnaissance de commandes vocales
  VoiceRecognizer VR = new VoiceRecognizer(2,3) ;
  
  // Création d'une instance de matrice de LED
  LEDMatrixController LED = new LEDMatrixController(&VR) ;
  LED.setupMatrix(); // il faut une instance de matrice
}

void run() {
  cmd = getCommand() ;

  if (cmd == 9) { // Turn_on_the_TV
    Turn_on_TV() ;
  }
  else if (cmd == 1) { // Turn_on_the_light
    Turn_on_light() ;
  }
  else if (cmd == 20) { // Voice_drawing
    Voice_drawing() ;
  }
  else {
    cout << "Commande non prise en charge" << endl ;
  }
}
