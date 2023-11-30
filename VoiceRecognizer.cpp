#include <VoiceRecognizer.h>

VoiceRecognizer::VoiceRecognizer(int rxPin, int txPin) : softSerial(rxPin, txPin), cmd(0) {
    softSerial.begin(9600);
    softSerial.listen();
}

VoiceRecognizer::~VoiceRecognizer() {
    // Destructeur
}

int VoiceRecongizer::getCommand() {
    if(softSerial.available())
    {
        cmd = softSerial.read();
    }
    else {
      throw 1 ;
    }
    return cmd ; // Traiter une exception si on ne passe pas dans le if
}
