//Class define mice, subclass of Animal
#ifndef MICE_H
#define MICE_H
#include "Animal.h"
using namespace std; 

class Mice: public Animal{
    public:
        Mice(); //Default Constructor
        bool attack(Character* piece);//Method inherited from Animal, can only attack Mice, Soldier and Fortress. 
        ~Mice(); //Destructor
};


#endif