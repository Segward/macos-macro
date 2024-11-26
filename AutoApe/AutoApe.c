#include "Ape.h"

int main() {

    usleep(3000000);

    while (true) {

        // This takes a minute but we ignore it
        StartNewGame();

        // Time begin here 
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

        // Time to here is roughly 1 minute
        // One loop is roughly 15 seconds and I need it to last 30 minutes so 120 loops
        for (int i = 0; i < 120; ++i) {
            Transform();
            UseNegativeHail();
            ResetCharacter();
        }

        // Time to here is roughly 31.5 minutes
        SetApeTransformation();
        ApeTransform();

        // Press 2 every minute for 30 minutes
        for (int i = 0; i < 30; ++i) {
            usleep(60000000);
            SimulateKeyStroke(kVK_ANSI_2);
        }

        // Set lssj transformation
        SetLssjTransformation();
       
    }

    return 0;
}