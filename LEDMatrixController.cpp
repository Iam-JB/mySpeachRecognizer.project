#include <LEDMatrixController.h>

const uint64_t Emoji[] = 
{
  0x3c4299a581a5423c,
  0x3c4281bd81a5423c,
  0x3c42a59981a5423c,
};
const int EMOJI_LEN = sizeof(Emoji)/8;

const uint64_t Carre[] = {
  0xff000001010000ff, 0xff000003030000ff, 0xff000006060000ff,
  0xff00000c0c0000ff, 0xff000018180000ff, 0xff000030300000ff,
  0xff000060600000ff, 0xff0000c0c00000ff, 0xff000080800000ff,
  0xff0000c0c00000ff, 0xff000060600000ff, 0xff000018180000ff,
  0xff00000c0c0000ff, 0xff000006060000ff, 0xff000003030000ff,
  0xff000001010000ff
};
const int CARRE_LEN = sizeof(Carre)/8;

const uint64_t* animation[] = { Emoji[], Carre[] };

LEDMatrixController::LEDMatrixController(VoiceRecognizer* VR) {
  this->MyVoiceRecognizer = VR;
}

LEDMatrixController::~LEDMatrixController() {
    // Destructeur
}

void LEDMatrixController::setupMatrix() {
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
    SERIAL.println("Matrix init success!!!");
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
    int Animation_Len = sizeof(*Animation[animation_index])/8;
    for (int i = 0;i < Animation_Len;i++){ // i dépend du nombre d'images de l'animation !
        matrix.writeOnePicture(*Animation[animation_index]); // comment mettre l'animation i de l'emplacement pointé par Animation[] ?
        delay(500);
        }
    cmd = this.getCommand(); // il faut une instance de voice recognizer
  }
      
}

void LEDMatrixController::Turn_on_the_light() {

      int cmd = 1;
      brightness = 0;
      
     while (cmd != Turn_off_the_light) {
        if (cmd == Decrease_temperature) {
          if (brightness != 0){
           brightness-- ;

          }
        }
        if (cmd == Increase_temperature) { 
          if (brightness != 5){
            brightness++ ; 
          }
        }
        matrix.setBrightness(brightness);
        matrix.writeOnePicture(0xffffffffffffffff);

	cmd = this.getCommand();
      }
    }
        
 }
