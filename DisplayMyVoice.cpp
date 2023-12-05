using namespace std ;

void init(){
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
  
}
