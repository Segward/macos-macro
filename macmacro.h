#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

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
    CGEventRef event = CGEventCreate(NULL);
    CGPoint mouseLocation = CGEventGetLocation(event);
    CFRelease(event);
    usleep(100000); 

    CGEventRef mouseDownEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseDownEvent);
    CFRelease(mouseDownEvent);
    usleep(100000);

    CGEventRef mouseUpEvent = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, mouseUpEvent);
    CFRelease(mouseUpEvent);
    usleep(100000);
}

// Function to simulate key stroke using key press and key release
void SimulateKeyStroke(CGKeyCode KeyCode) {
    SimulateKeyPress(KeyCode);
    usleep(50000);
    SimulateKeyRelease(KeyCode);
    usleep(50000);
}

// Function to open a specific application
void OpenBrowser(const char* browser, const char* url) {
    char command[256];
    sprintf(command, "open -a '%s' '%s'", browser, url);
    system(command);
}   

// Function to close all instances of Brave Browser
void CloseBrowser(const char* browser) {
    char command[256];
    sprintf(command, "killall '%s'", browser);
    system(command);
}

// Function to move the mouse to a specific position offset from the current position
void MoveMouse(int x, int y, int duration) {
    CGEventRef event = CGEventCreate(NULL);
    CGPoint mouseLocation = CGEventGetLocation(event);
    CFRelease(event);

    CGPoint newMouseLocation = CGPointMake(mouseLocation.x + x, mouseLocation.y + y);
    int steps = duration / 10;
    float stepX = (newMouseLocation.x - mouseLocation.x) / steps;
    float stepY = (newMouseLocation.y - mouseLocation.y) / steps;

    for (int i = 0; i < steps; i++) {
        mouseLocation.x += stepX;
        mouseLocation.y += stepY;
        CGEventRef moveEvent = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved, mouseLocation, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, moveEvent);
        CFRelease(moveEvent);
        usleep(1000); 
    }

    CGEventRef moveEvent = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved, newMouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);
}

// Function to set the mouse position
void SetMousePosition(int x, int y) {
    CGPoint newMouseLocation = CGPointMake(x, y);
    CGEventRef moveEvent = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved, newMouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);
}