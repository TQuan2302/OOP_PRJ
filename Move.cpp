//Implementation of Move.h
#include "Move.h"
#include <iostream>

using namespace std;

// default constructor
Move::Move(){
    old_X = -1;
    old_Y = -1;
    new_X = -1;
    new_Y = -1;
}
// define struct move
Move::Move(int oldX, int oldY, int newX, int newY){//Change the coordinate of old square to new square
    old_X = oldX;
    old_Y = oldY;
    new_X = newX;
    new_Y = newY;
}