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
  
  unsigned int threshold = 200000;
  unsigned int min = threshold - 10000;
  unsigned int max = threshold + 10000;

  int i = 0;
  int j = 0;
  while (true) {
    if (i % 1000 == 0) {
      printf("Charging\n");
      usleep(10000000);
      SimulateKeyPress(keyCodeC);
      usleep(3000000);
      SimulateKeyRelease(keyCodeC);
      usleep(1000);
    }

    if (i % 10 == 0) {
      printf("Iteration %d\n", i);
      CGKeyCode skill = keyCode1 + (j % 4);
      SimulateKeyPress(skill);
      usleep(1000);
      SimulateKeyRelease(skill);
      usleep(1000);
      j++;
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
