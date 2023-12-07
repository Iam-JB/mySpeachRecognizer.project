#ifndef DISPLAYMYVOICE_H
#define DISPLAYMYVOICE_H
#include "LEDMatrixController.h"
#include "VoiceRecognizer.h"

class DisplayMyVoice {
public:
    // Constructeur & Destructeur
    DisplayMyVoice();
    ~DisplayMyVoice();

    // Fonctions
  void init();
  void run();

};

#endif



