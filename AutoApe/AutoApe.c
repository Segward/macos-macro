#include "Ape.h"

int main() {

    usleep(3000000);

    while (true) {

        // Open game
        StartNewGame();

        // Go to ape
        Transform();
        StartFlight();
        usleep(1000000);
        SimulateKeyPress(kVK_ANSI_W);
        SimulateKeyPress(kVK_ANSI_D);
        SimulateKeyPress(kVK_Space);
        SimulateKeyPress(kVK_Shift);
        usleep(6000000);
        SimulateKeyRelease(kVK_ANSI_D);
        SimulateKeyRelease(kVK_Space);
        SimulateKeyPress(kVK_Control);
        usleep(6000000);
        SimulateKeyRelease(kVK_Shift);
        SimulateKeyRelease(kVK_ANSI_W);
        SimulateKeyRelease(kVK_Control);
        usleep(1000000);
        UseNegativeHail();
        ResetCharacter();

        // One loop is roughly 15 seconds and I need it to last 30 minutes so 120 loops
        for (int i = 0; i < 120; ++i) {
            Transform();
            UseNegativeHail();
            ResetCharacter();
        }

        // Ape transformation and afk for 30 minutes
        SetApeTransformation();
        ApeTransform();
        for (int i = 0; i < 30; ++i) {
            usleep(60000000);
            SimulateKeyStroke(kVK_ANSI_2);
        }

        // Set lssj transformation
        SetLssjTransformation();
       
    }

    return 0;
}