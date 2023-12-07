#include "LEDMatrixController.h"

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

const uint64_t* animation[] = { Emoji, Carre };

int cmd;

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
}

void LEDMatrixController::Turn_on_TV(){

  cmd = 9;
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
    int Animation_Len = sizeof(animation[animation_index])/8;
    for (int i = 0;i < Animation_Len;i++){ // i dépend du nombre d'images de l'animation !

      matrix.writeOnePicture(animation[animation_index][i]); // comment mettre l'animation i de l'emplacement pointé par Animation[] ?
	    matrix.display();
	    delay(300);
    }
    cmd = this->MyVoiceRecognizer->getCommand(); // il faut une instance de voice recognizer
  }
      
}

void LEDMatrixController::Turn_on_light() {

      cmd = 1;
      int brightness = 1;
      
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
	      matrix.display();

	      cmd = this->MyVoiceRecognizer->getCommand();
      }
      brightness = 1 ; // Fonctionnalité éteindre la lumière
      matrix.setBrightness(brightness);
      matrix.writeOnePicture(0x000000000000001) ;
      matrix.display() ;
    }
    
 


void LEDMatrixController::Voice_drawing(){
//Control Vocal

  cmd = 20;
  uint8_t x=0;
  uint8_t y=0;

      while ( cmd != Stop ){
        if (cmd == Go){
          matrix.writePixel(x,y,true);
          matrix.display();
        }
        else {
          //blink : permet de repérer le curseur
          matrix.writePixel(x,y,true);
          matrix.display();
          delay(100);
          matrix.writePixel(x,y,false);
          matrix.display();
          delay(50);
        }

        cmd = this->MyVoiceRecognizer->getCommand();

        // Règle x si on veut déplacer le curseur à gauche
        if ( cmd == Left){
          if (x != 0){
            x--;
          }
          else {
            x = 7;
          }
        }
        // Règle x si on veut déplacer le curseur à droite
        if ( cmd == Right){
          if (x != 7){
            x++;
          }
          else {
            x = 0;
          }
        }
        // Règle y si on veut déplacer le curseur en haut
        if ( cmd == Up){
          if (y != 0){
            y--;
          }
          else {
            y = 7;
          }
        }

        // Règle y si on veut déplacer le curseur en bas
        if ( cmd == Down){
          if (y != 7){
            y++;
          }
          else {
            y = 0;
          }
        }

      }
    
}
