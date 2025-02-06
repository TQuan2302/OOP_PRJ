//Implementation of Mice.h
#include "iostream"
#include "Mice.h"
using namespace std; 

Mice:: Mice():Animal("mice"){}

bool Mice::attack(Character* piece){//Return true if the target is elephant, fortress or soldier. Else return false
    if(piece != nullptr && piece->getColor() != color &&
       (piece->getName() == "elephant" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Mice::~Mice(){} 