#include "../MacMacro.h"
#include <time.h>  

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