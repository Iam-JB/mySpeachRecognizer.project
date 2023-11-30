#include <VoiceRecognizer.h>
#include <LEDMatrixController.h>

using namespace std ;

int DisplayMyVoice() {
  try {
    
    // Création d'une instance de reconnaissance de commandes vocales
    VoiceRecognizer(2,3) ;

  }
  catch (1) {
    cout << "Aucune commande lue." << endl ;
  }
  
  return 0 ;
}
