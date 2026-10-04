#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

const int INFO = 1;
const int WARN = 2;
const int ERROR = 3;

// Debug output goes to the same serial port as the monome protocol and
// corrupts it, so it is disabled by default. Set to INFO to enable.
const int DEBUG_LEVEL = ERROR + 1;

void debug(int level, const char *message);
void debug(int level, String message);

void debugln(int level, const char *message);
void debugln(int level, String message);
void debugln(int level);

void debugf(int level, const char *message, ...);
void debugf(int level, String message, ...);

void debugfln(int level, const char *message, ...);
void debugfln(int level, String message, ...);

#endif