//Class define the Players in the game, each player has 8 animals, 1 fortress, 3 soldiers
//The class hold the list of animal, list of Soldier and the state of the fortress. 
#ifndef PLAYER_H
#define PLAYER_H
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"

#include<iostream>
using namespace std; 

class Player{
    private:
        Animal** animalList; //List of animal in the team
        Fortress* fortress; //The fortress
        Soldier** soldierList; //List of all Soldiers in the team. 
    public:
        Player(); //Constructor; 
        Animal** getAnimalList(); //Get the list of Animal
        Fortress* getFortress(); //Get the fortress
        Soldier** getSoldierList(); //Get the list of Soldier. 
        ~Player(); //Destructor for delete the dynamic allocated memory. 
};

#endif
