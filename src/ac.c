#include "macmacro.h"
#include <time.h>  

unsigned int getRandomDelay(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("Needs specified delay threshold in microseconds 10^6\n");
      return 1;
    }
  
    if (argc != 2) {
      printf("Needs specified delay threshold in microseconds 10^6\n");
      return 1;
    }

    unsigned int threshold = atoi(argv[1]);
    srand(time(NULL));
    usleep(3000000);
    printf("App started\n");

    unsigned int min = threshold - 1000;
    unsigned int max = threshold + 50000;

    while (true) {
        SimulateMouseClick();
        unsigned int delay = getRandomDelay(min, max);
        printf("Next click in %u microseconds\n", delay);
        usleep(delay);
    }

    return 0;
}
