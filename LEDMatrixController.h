#ifndef LEDMATRIXCONTROLLER_H
#define LEDMATRIXCONTROLLER_H
#include <Arduino.h>
#include <grove_two_rgb_led_matrix.h>


class LEDMatrixController {
private:
  GroveTwoRGBLedMatrixClass matrix;
  VoiceRecognizer* MyVoiceRecognizer ;
public:
    // Constructeur & Destructeur
    LEDMatrixController(VoiceRecognizer* VR);
    ~LEDMatrixController();

    // Fonctions
  void setupMatrix();
  void Turn_on_the_TV();
  void Turn_on_the_light();

};

#endif
