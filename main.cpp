#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h> // For virtual key codes
#include <iostream>
#include <unistd.h>
#include <cstdlib> // For system function

// Function to simulate key press
void SimulateKeyPress(CGKeyCode KeyCode) {
    CGEventRef KeyDownEvent = CGEventCreateKeyboardEvent(NULL, KeyCode, true);
    CGEventPost(kCGHIDEventTap, KeyDownEvent);
    CFRelease(KeyDownEvent);
}

// Function to simulate key release
void SimulateKeyRelease(CGKeyCode KeyCode) {
    CGEventRef KeyUpEvent = CGEventCreateKeyboardEvent(NULL, KeyCode, false);
    CGEventPost(kCGHIDEventTap, KeyUpEvent);
    CFRelease(KeyUpEvent);
}

// Function to check if a specific key is pressed
bool IsKeyPressed(CGKeyCode KeyCode) {
    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, KeyCode);
}

// Function to check if the left mouse button is pressed
bool IsLeftMouseButtonPressed() {
    return CGEventSourceButtonState(kCGEventSourceStateHIDSystemState, kCGMouseButtonLeft);
}

// Function to simulate a left mouse click
void SimulateMouseClick() {
    // Get the current mouse position
    CGEventRef event = CGEventCreate(NULL);
    CGPoint mouseLocation = CGEventGetLocation(event);
    CFRelease(event);

    // Small delay to make the click noticeable
    usleep(100000); // Sleep for 100ms

    // Create and post a mouse down event
    CGEventRef mouseDownEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseDownEvent);
    CFRelease(mouseDownEvent);

    // Small delay to make the click noticeable
    usleep(100000); // Sleep for 100ms

    // Create and post a mouse up event
    CGEventRef mouseUpEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseUpEvent);
    CFRelease(mouseUpEvent);

    // Small delay to safeguard 
    usleep(100000); // Sleep for 100ms
}

// Function to simulate key stroke using key press and key release
void SimulateKeyStroke(CGKeyCode KeyCode) {
    SimulateKeyPress(KeyCode);
    usleep(50000); // Sleep for 50ms
    SimulateKeyRelease(KeyCode);
    usleep(50000); // Sleep for 50ms
}

// Main function
int main() {

    while (true) {
        // Open Brave Browser if 'B' is pressed
        if (IsKeyPressed(kVK_ANSI_B)) {
            system("open -a 'Brave Browser' 'https://www.google.com'");
            usleep(3000000); // Sleep for 3 seconds
            system("kill -9 $(pgrep 'Brave Browser')");
        }

        // Simulate key press for 'R' and '9' if 'X' is pressed
        if (IsKeyPressed(kVK_ANSI_X)) {
            SimulateKeyStroke(kVK_ANSI_R);
            SimulateKeyStroke(kVK_ANSI_9);
        }

        // Check if the left mouse button is pressed
        if (IsLeftMouseButtonPressed()) {
            SimulateMouseClick();
            SimulateMouseClick();
        }

        // Break at escape key press
        if (IsKeyPressed(kVK_Escape)) {
            std::cout << "Exiting." << std::endl;
            break;
        }

        usleep(10000); // Sleep for 10 milliseconds to prevent high CPU usage
    }

    return 0;
}