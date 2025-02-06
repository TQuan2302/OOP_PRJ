//Implementation of Player.h
#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

Player::Player(){
    //AnimalList:
    animalList = new Animal*[8];
    for(int i = 0; i<8 ; i++){
        animalList[i] = nullptr; 
    }
    // make 3 types of animal
    for(int i = 0; i<8; i++){
        if(i < 3){
            animalList[i] = new Mice();
        }
        else if(i<6){
            animalList[i] = new Dog();
        }
        else{
            animalList[i] = new Elephant();    
        }
    }
    //Fortress:
    fortress = new Fortress;

    //SoldierList:
    soldierList = new Soldier*[3];
    for(int i = 0; i<3 ;i++){//Tempt fix for dynamic allocation error in createPlayer():
        soldierList[i] = new Soldier();
    }
}
Animal** Player::getAnimalList(){ //Return the list of animal in the game
    return animalList;
}
Fortress* Player::getFortress(){ //Return the fortress 
    return fortress;
}
Soldier** Player::getSoldierList(){ //Return the list of Soldier in the game. 
    return soldierList;
}

Player:: ~Player(){ //Delete the memory allocated to the list of animal, list of soldier and the fortress     delete[] animalList; 
    delete[] soldierList;
    delete fortress;
}
