#ifndef SNAKE

#define SNAKE

#include <iostream>
#include <vector>
#include "constants.h"
#include "ui.h"
using namespace std;

// initializing the snake with some initial size and direction
void init_snake();

// checks for collision with border and itself
bool has_collision();

// prints the occurence of snake
void paint_snake();

// controls the movement of snake
pair<int, int> move_snake(int);

// on_consume grows the snake
void grow_snake();

#endif