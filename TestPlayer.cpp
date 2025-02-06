#include<iostream>
#include "TestPlayer.h"
#include "Player.h"
#include "Character.h"
using namespace std;



void TestPlayer:: runTestPlayer(){
        cout << "Test Constructor" << endl; 
        TestConstructor(); 
        cout << endl; 
        cout << "Test TestGetAnimalList()" << endl; 
        TestGetAnimalList(); 
        cout << endl; 
        cout << "Test TestgetFortress()" << endl; 
        TestgetFortress(); 
        cout << endl; 
        cout << "Test TestGetSoldierList()" << endl; 
        TestGetSoldierList(); 
        cout << endl; 
        cout << "Test TestDestructor()" << endl; 
}


void TestPlayer::  TestConstructor(){
    Player player1; 
    Animal** animalList = player1.getAnimalList();
    string name = ""; 
    for(int i = 0; i<8; i++){
        if(i < 3){
            name = "mice"; 
        }
        else if(i<6){
            name = "dog"; 
        }
        else{
            name = "elephant"; 
        }

        if(!animalList[i]->getName().compare(name) && !animalList[i]->getColor().compare(" ")){
                cout << " " <<  i + 1 << "th Default name correct, default color correct, constructor passed" << endl; 
        }
        else{
            cout << " " <<  i + 1 << "th Constructor failed" << endl; 
        }
    }

}
void TestPlayer:: TestGetAnimalList(){
    Player player1; 
    string name = ""; 
    Animal** animalList = player1.getAnimalList();
    for(int i = 0; i<8; i++){
        if(i < 3){
            name = "mice"; 
        }
        else if(i<6){
            name = "dog"; 
        }
        else{
            name = "elephant"; 
        }

       if(!animalList[i]->getName().compare(name) && !animalList[i]->getColor().compare(" ")){
            cout << " " <<  i + 1 << "th animal default name correct, default color correct, getAnimalList() passed" << endl; 
       }
       else if(animalList[i] == nullptr){
        cout << " " <<  i + 1 << "th getAnimalList() failed" << endl; 
       }
    }
}
void TestPlayer:: TestgetFortress(){
    Player player2; 
    Fortress* fortressList = player2.getFortress(); 
    
    if(!fortressList->getName().compare("fortress") && !fortressList->getColor().compare(" ")){
        cout << "fortress default name correct, default color correct, getAnimalList() passed" << endl; 
    }
    
}
void TestPlayer:: TestGetSoldierList(){
    Player player1; 
    Soldier** soldierList = player1.getSoldierList();
    for(int i = 0; i<3; i++){
       if(!soldierList[i]->getName().compare("soldier") && !soldierList[i]->getColor().compare(" ")){
            cout << " " <<  i + 1 << "th soldier default name correct, default color correct, getAnimalList() passed" << endl; 
       }
       else if(soldierList[i] == nullptr){
        cout << " " <<  i + 1 << "th GetSoldierList() failed" << endl; 
       }
    }
}
