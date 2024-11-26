#include "../macmacro.hpp"
#include <cstdlib> 
#include <ctime>  

int main() {

    srand(time(NULL));
    usleep(3000000);

    while (true) {
        SimulateMouseClick();
        unsigned int delay = 100000 + (rand() % (2000000 - 100000 + 1));
        usleep(delay); 
    }

    return 0;
}