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
  CGKeyCode keyCodeV = 9;
  CGKeyCode keyCode1 = 18;
  CGKeyCode keyCode2 = 19;
  CGKeyCode keyCode3 = 20;
  CGKeyCode keyCode4 = 21;

  unsigned int threshold = 20000;
  unsigned int min = threshold - 5000;
  unsigned int max = threshold + 5000;

  int i = 0;
  while (true) {
    if (i % 1000 == 0) {
      SimulateKeyPress(keyCodeC);
      usleep(3000000);
      SimulateKeyRelease(keyCodeC);
    }

    if (i % 10) {
      SimulateKeyPress(keyCode1);
      usleep(1000);
      SimulateKeyRelease(keyCode1);
      SimulateKeyPress(keyCode2);
      usleep(1000);
      SimulateKeyRelease(keyCode2);
      SimulateKeyPress(keyCode3);
      usleep(1000);
      SimulateKeyRelease(keyCode3);
      SimulateKeyPress(keyCode4);
      usleep(1000);
      SimulateKeyRelease(keyCode4);
      usleep(1000);
    }

    SimulateKeyPress(keyCodeV);
    usleep(1000);
    SimulateKeyRelease(keyCodeV);

    unsigned int delay = getRandomDelay(min, max);
    printf("Next click in %u microseconds\n", delay);
    usleep(delay);
    i++;
  }

  return 0;
}
