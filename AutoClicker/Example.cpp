#include "../macmacro.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to generate a random delay between 100 milliseconds and 2 seconds
unsigned int getRandomDelay() {
    return 100000 + (rand() % (2000000 - 100000 + 1));
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Delay for 3 seconds
    usleep(3000000); // Sleep for 3 seconds

    while (true) {
        // Simulate mouse click
        SimulateMouseClick();

        // Get a random delay between 100 milliseconds and 2 seconds
        unsigned int delay = getRandomDelay();
        usleep(delay); // Sleep for the random delay
    }

    return 0;
}