#include <LEDMatrixController.h>

LEDMatrixController::LEDMatrixController() {
    // Constructeur
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