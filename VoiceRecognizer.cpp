#include "VoiceRecognizer.h"

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
    return cmd ; // Traiter une exception si on ne passe pas dans le if
}
