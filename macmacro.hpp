#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

class MacMacro {
public:
    void SimulateKeyPress(CGKeyCode KeyCode);
    void SimulateKeyRelease(CGKeyCode KeyCode);
    bool IsKeyPressed(CGKeyCode KeyCode);
    bool IsLeftMouseButtonPressed();
    void SimulateMouseClick();
    void SimulateKeyStroke(CGKeyCode KeyCode);
    void OpenBraveBrowser(const char* URL);
    void CloseBraveBrowser();
    void MoveMouse(int x, int y, int duration);
};

// Function to simulate key press
void MacMacro::SimulateKeyPress(CGKeyCode KeyCode) {
    CGEventRef KeyDownEvent = CGEventCreateKeyboardEvent(NULL, KeyCode, true);
    CGEventPost(kCGHIDEventTap, KeyDownEvent);
    CFRelease(KeyDownEvent);
}

// Function to simulate key release
void MacMacro::SimulateKeyRelease(CGKeyCode KeyCode) {
    CGEventRef KeyUpEvent = CGEventCreateKeyboardEvent(NULL, KeyCode, false);
    CGEventPost(kCGHIDEventTap, KeyUpEvent);
    CFRelease(KeyUpEvent);
}

// Function to check if a specific key is pressed
bool MacMacro::IsKeyPressed(CGKeyCode KeyCode) {
    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, KeyCode);
}

// Function to check if the left mouse button is pressed
bool MacMacro::IsLeftMouseButtonPressed() {
    return CGEventSourceButtonState(kCGEventSourceStateHIDSystemState, kCGMouseButtonLeft);
}

// Function to simulate a left mouse click
void MacMacro::SimulateMouseClick() {
    // Get the current mouse position
    CGEventRef event = CGEventCreate(NULL);
    CGPoint mouseLocation = CGEventGetLocation(event);
    CFRelease(event);

    // Small delay to make the click noticeable
    usleep(200000); // Sleep for 200ms

    // Create and post a mouse down event
    CGEventRef mouseDownEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseDownEvent);
    CFRelease(mouseDownEvent);

    // Small delay to make the click noticeable
    usleep(200000); // Sleep for 200ms

    // Create and post a mouse up event
    CGEventRef mouseUpEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseUpEvent);
    CFRelease(mouseUpEvent);

    // Small delay to safeguard 
    usleep(200000); // Sleep for 200ms
}

// Function to simulate key stroke using key press and key release
void MacMacro::SimulateKeyStroke(CGKeyCode KeyCode) {
    SimulateKeyPress(KeyCode);
    usleep(50000); // Sleep for 50ms
    SimulateKeyRelease(KeyCode);
    usleep(50000); // Sleep for 50ms
}

void MacMacro::OpenBraveBrowser(const char* URL) {
    std::string command = "open -a 'Brave Browser' '" + std::string(URL) + "'";
    system(command.c_str());
    usleep(3000000); // Sleep for 3 seconds
}   

void MacMacro::CloseBraveBrowser() {
    system("kill -9 $(pgrep 'Brave Browser')");
}

void MacMacro::MoveMouse(int x, int y, int duration) {
    // Get the current mouse position
    CGEventRef event = CGEventCreate(NULL);
    CGPoint mouseLocation = CGEventGetLocation(event);
    CFRelease(event);

    // Calculate the new mouse position
    CGPoint newMouseLocation = CGPointMake(mouseLocation.x + x, mouseLocation.y + y);

    // Calculate the number of steps
    int steps = duration / 10;

    // Calculate the step size
    float stepX = (newMouseLocation.x - mouseLocation.x) / steps;
    float stepY = (newMouseLocation.y - mouseLocation.y) / steps;

    // Move the mouse in steps
    for (int i = 0; i < steps; i++) {
        mouseLocation.x += stepX;
        mouseLocation.y += stepY;

        CGEventRef moveEvent = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved, mouseLocation, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, moveEvent);
        CFRelease(moveEvent);

        usleep(10000); // Sleep for 10ms
    }

    // Move the mouse to the final position
    CGEventRef moveEvent = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved, newMouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);
}