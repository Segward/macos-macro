#include "../MacMacro.h"

void StartNewGame() {
    OpenBrowser("Brave Browser", "https://www.roblox.com/games/8246874626/Scythe-Dragon-Soul-Anime-Adventure?privateServerLinkCode=45409394009317100111510273891252");
    usleep(25000000);
    CloseBrowser("Brave Browser");
    SimulateKeyStroke(kVK_Return);
    usleep(30000000);
}

void StartFlight() {
    SimulateKeyStroke(kVK_Space);
    usleep(100000);
    SimulateKeyStroke(kVK_Space);
    usleep(100000);
}

void ApeTransform() {
    SimulateKeyStroke(kVK_ANSI_R);
    usleep(10000000);
}

void Transform() {
    SimulateKeyStroke(kVK_ANSI_R);
    usleep(2000000);
    SimulateKeyStroke(kVK_ANSI_9);
    usleep(2000000);
}

void UseNegativeHail() {
    SimulateKeyStroke(kVK_ANSI_4);
    usleep(4000000);
}

void ResetCharacter() {
    SimulateKeyStroke(kVK_Escape);
    usleep(1000000);
    SimulateKeyStroke(kVK_ANSI_R);
    usleep(1000000);
    SimulateKeyStroke(kVK_Return);
    usleep(5000000);
}

void SetApeTransformation() {
    SimulateKeyStroke(kVK_ANSI_M);
    usleep(100000);
    MoveMouse(-300, -120, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(100, -40, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(0, 300, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(400, 50, 1000);
    SimulateMouseClick();
    usleep(100000);
    SimulateKeyStroke(kVK_ANSI_M);
}

void SetLssjTransformation() {
    SimulateKeyStroke(kVK_ANSI_M);
    usleep(100000);
    MoveMouse(-300, -120, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(100, -40, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(0, 400, 1000);
    SimulateMouseClick();
    usleep(100000);
    MoveMouse(400, -30, 1000);
    SimulateMouseClick();
    usleep(100000);
    SimulateKeyStroke(kVK_ANSI_M);
}