#ifndef LEDMATRIXCONTROLLER_H
#define LEDMATRIXCONTROLLER_H
#include <Arduino.h>
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"


class LEDMatrixController {
private:
  Matrix_8x8 matrix;
  VoiceRecognizer* MyVoiceRecognizer ;
public:
    // Constructeur & Destructeur
    LEDMatrixController(VoiceRecognizer* VR);
    ~LEDMatrixController();

    // Fonctions
  void setupMatrix();
  void Turn_on_the_TV();
  void Turn_on_the_light();
  void Voice_drawing();

};

#endif
