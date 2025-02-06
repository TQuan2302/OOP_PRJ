//Class define dog, subclass of Animal
#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog: public Animal{
public: 
    Dog(); 
    bool attack(Character* piece); //Method inherited from Animal, can only attack Mice, Soldier and Fortress. 
    ~Dog();
};

#endif