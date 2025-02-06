//Implementation of Elephant.h
#include <iostream>
#include "Elephant.h"
using namespace std; 

Elephant:: Elephant():Animal("elephant"){}

bool Elephant::attack(Character* piece){//Return true if the target is dog, fortress or soldier. Else return false
    if(piece != nullptr && piece->getColor() != color &&
       (piece->getName() == "dog" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Elephant::~Elephant(){}

