#include "macmacro.h"
#include <time.h>  

int main() {
    srand(time(NULL));
    usleep(3000000);
    printf("Starting the macro\n");

    CGKeyCode keyCodeE = 14;
    CGKeyCode keyCode1 = 18;
    CGKeyCode keyCode6 = 27;

    while (true) {
      SimulateKeyStroke(keyCodeE);
      usleep(1000000);
      MoveMouse(-200, 500, 2);
    }

    return 0;
}
