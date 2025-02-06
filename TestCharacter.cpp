#include<iostream>
#include "TestCharacter.h"

using namespace std; 

void TestCharacter:: runTestCharacter(){
    testDefaultContructor(); 
    testParameterizedConstructor(); 
    testGetName(); 
    testSetName(); 
    testGetColor(); 
    testSetColor();
    testAttack(); 
}
void TestCharacter:: testDefaultContructor(){
    Character c1; 
    if(!c1.getName().compare(" ")){
        cout << "Default constructor passed" << endl; 
    }
    else{
        cout << "Default constructor failed" << endl; 
    }

    if(c1.getName().compare("dog")){
        cout << "Default constructor passed" << endl; 
    }
    else{
        cout << "Default constructor failed" << endl; 
    }

    if(c1.getName().compare("elephant")){
        cout << "Default constructor passed" << endl; 
    }
    else{
        cout << "Default constructor failed" << endl; 
    }

    
    if(c1.getName().compare("mice")){
        cout << "Default constructor passed" << endl; 
    }
    else{
        cout << "Default constructor failed" << endl; 
    }

}
void TestCharacter:: testParameterizedConstructor(){
    Character c1("Character"); 
    if(!c1.getName().compare("Character")){
        cout << "Parameterized  constructor passed" << endl; 
    }
    else{
        cout << "Parameterized  constructor failed" << endl; 
    }


    if(c1.getName().compare("Character2")){
        cout << "Parameterized  constructor passed" << endl; 
    }
    else{
        cout << "Parameterized  constructor failed" << endl; 
    }
}
void TestCharacter:: testGetName(){
    Character c1("Character"); 
    if(!c1.getName().compare("Character")){
        cout << "testGetName passed" << endl; 
    }
    else{
        cout << "testGetName failed" << endl; 
    }
} 
void TestCharacter:: testSetName(){
    Character c1("Character"); 
    c1.setName("ChangeName"); 
    if(!c1.getName().compare("ChangeName")){
        cout << "testSetName passed" << endl; 
    }
    else{
        cout << "testSetName failed" << endl; 
    }
}

void TestCharacter::testGetColor(){
    Character c1("Character"); 
    if(!c1.getColor().compare(" ")){
        cout << "testGetColor passed" << endl; 
    }
    else{
        cout << "testGetColor failed" << endl; 
    }
}

void TestCharacter:: testSetColor(){
    Character c1("Character"); 
    c1.setColor("Violet"); 
    if(!c1.getColor().compare("Violet")){
        cout << "testSetColor passed" << endl; 
    }
    else{
        cout << "testSetColor failed" << endl; 
    }
}
void TestCharacter:: testAttack(){
    Character c1; 
    Character* c2 = new Character(); 
    if(c1.attack(c2) == false){
        cout << "Attack() passed" << endl;
    }
    else{
        cout << "Attack() passed" << endl;
    }
    delete c2; 

}


