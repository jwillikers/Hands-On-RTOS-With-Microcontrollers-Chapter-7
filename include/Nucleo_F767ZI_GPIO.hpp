#pragma once

#include <cstdint>

// Create a typedef defining a simple function pointer
// to be used for LED's
typedef void (*GPIOFunc)();

// this struct holds function pointers to turn each LED
// on and off
typedef struct {
  const GPIOFunc On;
  const GPIOFunc Off;
} LED;

uint_fast8_t ReadPushButton();

extern LED BlueLed;
extern LED GreenLed;
extern LED RedLed;
