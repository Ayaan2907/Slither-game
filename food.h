#include <vector>
#include <experimental/random>
#include <ncurses.h>
#include "constants.h"
using namespace std;

// checks if food is consumed by the snake or not-- T/F
bool consume_food(int x, int y);

// prints the food items
void paint_food();

// initializes all the food items(here its set to 10)
void init_food();