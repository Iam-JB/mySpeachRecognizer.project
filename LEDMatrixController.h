#ifndef LEDMATRIXCONTROLLER_H
#define LEDMATRIXCONTROLLER_H

#include <grove_two_rgb_led_matrix.h>

class LEDMatrixController {
private:
    GroveTwoRGBLedMatrixClass matrix;
public:
    // Constructeur & Destructeur
    LEDMatrixController();
    ~LEDMatrixController();

    // Fonctions
  void setupMatrix();
  void Turn_on_the_TV();

};

#endif
