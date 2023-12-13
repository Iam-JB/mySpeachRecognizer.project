#include "VoiceRecognizer.h"
#define NO_CMD -1

VoiceRecognizer::VoiceRecognizer(int rxPin, int txPin) : softSerial(rxPin, txPin), cmd(0) {
    softSerial.begin(9600);
    softSerial.listen();
}

VoiceRecognizer::~VoiceRecognizer() {
    // Destructeur
}

int VoiceRecognizer::getCommand() {
  char cmd;
    if(softSerial.available())
    {
        cmd = softSerial.read();
    }
    else {
        throw NO_CMD ;
    }
    return cmd ; // Traiter une exception si on ne passe pas dans le if
}
