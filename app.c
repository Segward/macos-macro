#include "macmacro.h"
#include <time.h>  

int main() {
    srand(time(NULL));
    usleep(3000000);
    printf("AutoClicker started\n");

    while (true) {
        SimulateMouseClick();
        unsigned int delay = 100000 + (rand() % (2000000 - 100000 + 1));
        printf("Next click in %u microseconds\n", delay);
        usleep(delay);
    }

    return 0;
}
