#include "Ape.h"

int main() {

    usleep(3000000);

    while (true) {

        // Begin the loop and get to ape
        StartNewGame();
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
        for (int i = 0; i < 50; ++i) {
            Transform();
            UseNegativeHail();
            ResetCharacter();
        }

        // Since each loop is like 15 seconds, this will take 12.5 minutes
        // Time to here is roughly 13.5 minutes
        // I need to make a wait to make time to 31 minutes
        // I will make a wait of 17.5 minutes which is 1050 seconds
        usleep(1050000000); 

        // Time to here is roughly 31 minutes
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