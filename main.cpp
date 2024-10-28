#include "macmacro.hpp"

// Main function
int main() {

    // Create an instance of the MacMacro class
    MacMacro Macro;

    while (true) {
        // Open Brave Browser if 'B' is pressed
        if (Macro.IsKeyPressed(kVK_ANSI_B)) {
            Macro.OpenBraveBrowser("https://www.google.com");
            Macro.CloseBraveBrowser();
        }

        // Simulate key press for 'R' and '9' if 'X' is pressed
        if (Macro.IsKeyPressed(kVK_ANSI_X)) {
            Macro.SimulateKeyStroke(kVK_ANSI_R);
            Macro.SimulateKeyStroke(kVK_ANSI_9);
        }

        // Check if the left mouse button is pressed
        if (Macro.IsLeftMouseButtonPressed()) {
            Macro.SimulateMouseClick();
            Macro.SimulateMouseClick();
        }

        // Break at escape key press
        if (Macro.IsKeyPressed(kVK_Escape)) {
            std::cout << "Exiting." << std::endl;
            break;
        }

        usleep(10000); // Sleep for 10 milliseconds to prevent high CPU usage
    }

    return 0;
}