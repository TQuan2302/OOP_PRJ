//Implementation of Dog.h
#include<iostream>
#include "Dog.h"
using namespace std; 

Dog:: Dog(): Animal("dog"){
}
bool Dog::attack(Character* piece){//Return true if the target is mice, fortress or soldier. Else return false
    if(piece != nullptr && piece->getColor() != color &&
       (piece->getName() == "mice" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Dog::~Dog(){} 