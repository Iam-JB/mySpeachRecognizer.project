#ifndef DISPLAYMYVOICE_H
#define DISPLAYMYVOICE_H
#include "LEDMatrixController.h"
#include "VoiceRecognizer.h"

class DisplayMyVoice {
private :
    char comd ;

    // Création d'une instance de reconnaissance de commandes vocales
    VoiceRecognizer* VR ;

    // Création d'une instance de matrice de LED
    LEDMatrixController* LED ;

public:
    // Constructeur & Destructeur
    DisplayMyVoice();
    ~DisplayMyVoice();

    // Fonctions
  void init();
  void run();
};

#endif



