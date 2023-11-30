#ifndef VOICERECOGNIZER_H
#define VOICERECOGNIZER_H

#include <SoftwareSerial.h>

// Définition de l'ensemble des commandes vocales possibles
#define Turn_on_the_light 1
#define Turn_off_the_light 2
#define PLay_music 3
#define Pause 4
#define Next 5
#define Previous 6
#define Up 7
#define Down 8
#define Turn_on_the_TV 9
#define Turn_off_the_TV 10
#define Increase_temperature 11
#define Decrease_temperature 12
#define What_is_the_time 13
#define Open_the_door 14
#define Close_the_door 15
#define Left 16
#define Right 17
#define Stop 18
#define Start 19
#define Mode_1 20
#define Mode_2 21
#define Go 22

class VoiceRecognizer {
private :
    SoftwareSerial softSerial ;
    int cmd ;
public :
    // Constructeur & Destructeur
    VoiceRecognizer(int rxPin, int txPin) ;
    ~VoiceRecognizer() ;

    // Assesseur
    int getCommand(void) ;
};

#endif
