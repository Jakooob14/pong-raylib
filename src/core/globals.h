#ifndef GLOBALS_H
#define GLOBALS_H
#include <random>

#include "raylib.h"
#include "../utils/timer_manager.h"

extern Font mechaFont;

// Random number engine
extern std::mt19937 rng;

extern TimerManager timerManager;

#endif //GLOBALS_H
