#include "macmacro.h"
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  usleep(3000000);
  printf("App started\n");

  CGKeyCode keyCodeE = 14;
  CGKeyCode keyCodeS = 1;
  CGKeyCode keyCodeA = 0;

  while (true) {
    OpenBrowser("Brave Browser", "https://www.roblox.com/games/8246874626/2x-KK-x100-Dragon-Soul-Anime-MMO?privateServerLinkCode=50476890616776440184631035939790");

    usleep(15000000);
    CloseBrowser("Brave Browser");
    usleep(5000000);
    SimulateKeyPress(keyCodeS);
    SimulateKeyPress(keyCodeA);
    usleep(600000);
    SimulateKeyRelease(keyCodeS);
    SimulateKeyRelease(keyCodeA);
    usleep(50000);
    SimulateKeyPress(keyCodeE);
    usleep(1000000);
    SimulateKeyRelease(keyCodeE);
    usleep(1000000);
    SimulateKeyPress(keyCodeE);
    usleep(1000000);
    SimulateKeyRelease(keyCodeE);
  }

  return 0;
}
