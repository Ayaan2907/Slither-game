#ifndef GAME

#define GAME

#include "constants.h"
#include "ui.h"
#include "snake.h"
#include "food.h"


// controls all the ticks of game, 
// All the actions, functions, key presses aare monitored by tick()
void tick(int key);

#endif