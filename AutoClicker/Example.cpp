#include "../macmacro.hpp"

// Main function
int main() {

    // Delay for 3 seconds
    usleep(3000000); // Sleep for 3 seconds

    while (true) {

        // Simulate mouse click
        SimulateMouseClick();
        usleep(100000); // Sleep for 100 ms

    }

    return 0;
}