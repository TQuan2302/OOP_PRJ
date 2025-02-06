//Implementation of Fortress.h
#include "Fortress.h"
#include "Character.h"

using namespace std;

Fortress::Fortress(): Character("fortress") {}

bool Fortress::attack(Character* piece){//Inherited method from Character, always return false. 
    return false;
}


Fortress::~Fortress(){}