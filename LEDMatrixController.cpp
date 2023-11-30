#include <LEDMatrixController.h>

LEDMatrixController::LEDMatrixController(VoiceRecognizer* VR) {
  this->MyVoiceRecognizer = VR;
}

LEDMatrixController::~LEDMatrixController() {
    // Destructeur
}

void LEDMatrixController::setupMatrix() {
    Wire.begin();
    SERIAL.begin(115200);
    waitForMatrixReady();
    uint16_t VID = 0;
    VID = matrix.getDeviceVID();
    if (VID != 0x2886) {
        SERIAL.println("Cannot detect led matrix !");
        while (1);
    }
    SERIAL.println("Matrix init success !");
}

void LEDMatrixController::Turn_on_the_TV(){

  int cmd = 9;
  int animation_index = 0; 
  while (cmd != Turn_off_the_TV) {
    if (cmd == Next) {
      if (animation_index == 5){
        animation_index = 0;
      }
      else {
        animation_index++; 
      }
    }
    if (cmd == Previous){
      if (animation_index == 0){
        animation_index = 5;
      }
      else {
        animation_index--; 
      }
    }
    matrix.displayColorAnimation(animation_index, 5000, false);
    cmd = VoiceRecognizer::getCommand(); // il faut une instance de voice recognizer
  }
      
}

void LEDMatrixController::Turn_on_the_light() {

  int cmd = 1;
  uint64_t Light_displayed[] = Light[] ;
      while (cmd != Turn_off_the_light) {
        if (cmd == Decrease_temperature) { // faudra il surcharger ==, < et > pour les uint64_t ? 
          if ( Light_displayed > Light_min){
            Light_displayed -= Light_increment;
          }
        }
        if (cmd == Increase_temperature) { 
          if ( Light_displayed < Light_max){
            Light_displayed += Light_increment;
          }
        }
        cmd = VoiceRecognizer::getCommand(); // il faut une instance de voice recognizer
        
      }

}
