//Class define Elephant, subclass of Animal
#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant: public Animal{
    public:
        Elephant(); 
        bool attack(Character* piece); ////Method inherited from Animal, can only attack Dog, Soldier and Fortress. 
        ~Elephant();
};

#endif