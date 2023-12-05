
using namespace std ;

void init(){
  char cmd ;
  setupMatrix();
  
  try {
    // Création d'une instance de reconnaissance de commandes vocales
    VR = new VoiceRecognizer(2,3) ;
    
    // Création d'une instance de matrice de LED
    LED = new LEDMatrixController(&VR) ;
  }
  catch (1) {
    cout << "Aucune commande lue." << endl ;
  }
}

void run() {
  cmd = getCommand() ;

  if (cmd == 9) { // Turn_on_the_TV
    Turn_on_the_TV() ;
  }
  else if (cmd == 1) { // Turn_on_the_light
    Turn_on_the_light() ;
  }
  else if (cmd == 20) { // Voice_drawing
    Voice_drawing() ;
  }
  else {
    cout << "Commande non prise en charge" << endl ;
  }
}
