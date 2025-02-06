#include <iostream>
#include "TestFortress.h"
#include "Character.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

using namespace std; 

void TestFortress:: TestConstructor(){
    cout << "Test constructor" << endl;
    Fortress f0; 
    if(!f0.getName().compare("fortress")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    if(f0.getName().compare(" ")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
}
void TestFortress::testName(){
    Fortress f1;
    cout << "Test setName() and getName()" << endl;
    f1.setName(" "); 
    if(!f1.getName().compare(" ")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
    f1.setName("mice"); 
    if(!f1.getName().compare("mice")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
}
void TestFortress:: testAttack(){
    Fortress f2; 
    // test different team
    f2.setColor("red");
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
    if(f2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(f2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(f2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(f2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(f2.attack(targetFortress) == false){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    // test same team
    f2.setColor("red");
    targetDog->setColor("red");
    targetElephant->setColor("red");
    targetMice->setColor("red");
    targetFortress->setColor("red");
    targetSoldier->setColor("red");
    cout << "Test same color" << endl;
    if(f2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(f2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(f2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(f2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(f2.attack(targetFortress) == false){
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
void TestFortress:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Fortress()
}

void TestFortress::testColor(){
    cout << "Test color" << endl;
    Fortress f3;
    // test default color
    if(f3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    f3.setColor("red");
    if(f3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    f3.setColor("blue");
    if(f3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
