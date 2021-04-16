#pragma once

#include <cstdint>

// Create a typedef defining a simple function pointer to be used for LED's
using GPIOFunc = void (*)();

// This struct holds function pointers to turn each LED on and off
struct LED {
  const GPIOFunc On;
  const GPIOFunc Off;
};

uint_fast8_t ReadPushButton();

extern LED BlueLed;
extern LED GreenLed;
extern LED RedLed;
