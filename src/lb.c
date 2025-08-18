#include "macmacro.h"
#include <time.h>  

int main() {
    srand(time(NULL));
    usleep(3000000);
    printf("Starting the macro\n");

    // https://eastmanreference.com/complete-list-of-applescript-key-codes
    CGKeyCode keyCodeE = 14;
    CGKeyCode keyCodeC = 8;
    CGKeyCode keyCode1 = 18; 

    while (true) {
      SimulateKeyStroke(keyCodeE);
      usleep(1000000);
      MoveMouse(-100, 410, 100);
      usleep(1000000);
      SimulateMouseClick();
      usleep(1000000);
      SimulateKeyStroke(keyCode1);
      usleep(7000000);
      SimulateKeyPress(keyCodeC);
      usleep(7500000);
      SimulateKeyRelease(keyCodeC);
      usleep(1000000);
    }

    return 0;
}
