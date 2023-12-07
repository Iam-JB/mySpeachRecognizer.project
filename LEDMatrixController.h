#ifndef LEDMATRIXCONTROLLER_H
#define LEDMATRIXCONTROLLER_H
#include <Arduino.h>
#include <Wire.h>
#include "VoiceRecognizer.h"
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
  void Turn_on_TV();
  void Turn_on_light();
  void Voice_drawing();

};

#endif
