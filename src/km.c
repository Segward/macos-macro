#include "macmacro.h"
#include <time.h>

unsigned int getRandomDelay(int min, int max) {
  return min + (rand() % (max - min + 1));
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  usleep(3000000);
  printf("App started\n");

  CGKeyCode keyCodeC = 8;
  unsigned int threshold = 1000000;
  unsigned int min = threshold - 1000;
  unsigned int max = threshold + 50000;

  int i = 0;
  while (true) {
    if (i % 100 == 0) {
      SimulateKeyPress(keyCodeC);
      usleep(3000000);
      SimulateKeyRelease(keyCodeC);
    }

    SimulateMouseClick();
    unsigned int delay = getRandomDelay(min, max);
    printf("Next click in %u microseconds\n", delay);
    usleep(delay);
    i++;
  }

  return 0;
}
