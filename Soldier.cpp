//Implementation of Soldier.h
#include <iostream>
#include "Character.h"
#include "Soldier.h"

using namespace std;

Soldier::Soldier() : Character("soldier") {}

bool Soldier::attack(Character* piece){//Always return false as soldier can not attack another piece
    return false;
}

Soldier:: ~Soldier(){}
