#include "../macmacro.hpp"

// Main function
int main() {

    // Create an instance of the MacMacro class
    MacMacro Macro;

    // Delay for 3 seconds
    usleep(3000000); // Sleep for 3 seconds

    while (true) {

        // Simulate key stroke 'E'
        Macro.SimulateKeyStroke(kVK_ANSI_E);
        usleep(1000000); // Sleep for 1 second

        // Simulate Mouse Move and Click
        Macro.MoveMouse(-80, 390, 500);
        Macro.SimulateMouseClick();
        usleep(1000000); // Sleep for 1 second

        // Simulate key stroke '1'
        Macro.SimulateKeyStroke(kVK_ANSI_1);
        usleep(2500000); // Sleep for 2 seconds and 500 milliseconds

        // Simulate key stroke '2'
        Macro.SimulateKeyStroke(kVK_ANSI_2);
        usleep(5000000); // Sleep for 5 second
        
        // Simulate key press 'C'
        Macro.SimulateKeyPress(kVK_ANSI_C);
        usleep(5000000); // Sleep for 5 seconds

        // Simulate key release 'C'
        Macro.SimulateKeyRelease(kVK_ANSI_C);
        usleep(5000000); // Sleep for 5 seconds
        
    }

    return 0;
}