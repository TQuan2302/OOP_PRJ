#include <iostream>
#include "TestElephant.h"
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"
#include "Soldier.h"
#include "Fortress.h"

using namespace std; 

void TestElephant:: TestConstructor(){
    cout << "Test constructor" << endl;
    Elephant e0; 
    if(!e0.getName().compare("elephant")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    if(e0.getName().compare(" ")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
}
void TestElephant::testName(){
    Elephant e1; 
    cout << "Test setName() and getName()" << endl;
    e1.setName(" "); 
    if(!e1.getName().compare(" ")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
    e1.setName("mice"); 
    if(!e1.getName().compare("mice")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
}
void TestElephant:: testAttack(){
    Elephant e2; 
    // test different team
    e2.setColor("red");
    Character* targetDog = new Dog();
    targetDog->setColor("blue");
    Character* targetMice = new Mice();
    targetMice->setColor("blue");
    Character* targetElephant = new Elephant();
    targetElephant->setColor("blue");
    Character* targetSoldier = new Soldier();
    targetSoldier->setColor("blue");
    Character* targetFortress = new Fortress();
    targetFortress->setColor("blue");
    cout << "Test attack" << endl;
    cout << "Test different color" << endl;
    if(e2.attack(targetDog) == true){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(e2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(e2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(e2.attack(targetSoldier) == true){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(e2.attack(targetFortress) == true){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    // test same team
    e2.setColor("red");
    targetDog->setColor("red");
    targetMice->setColor("red");
    targetElephant->setColor("red");
    targetFortress->setColor("red");
    targetSoldier->setColor("red");
    cout << "Test same color" << endl;
    if(e2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(e2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(e2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(e2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(e2.attack(targetFortress) == false){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
    delete targetSoldier;
    delete targetFortress;
}
void TestElephant:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Elephant()
}

void TestElephant::testColor(){
    cout << "Test color" << endl;
    Elephant e3;
    // test default color
    if(e3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    e3.setColor("red");
    if(e3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    e3.setColor("blue");
    if(e3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
