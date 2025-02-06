#include<iostream>
#include "TestSoldier.h"
#include "Character.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

using namespace std; 

void TestSoldier:: TestConstructor(){
    cout << "Test constructor" << endl;
    Soldier s0; 
    if(!s0.getName().compare("soldier")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    if(s0.getName().compare(" ")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
}
void TestSoldier::testName(){
    Soldier s1;
    cout << "Test setName() and getName()" << endl;
    s1.setName(" "); 
    if(!s1.getName().compare(" ")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
    s1.setName("a"); 
    if(!s1.getName().compare("a")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
}
void TestSoldier:: testAttack(){
    Soldier s2; 
    // test different team
    s2.setColor("red");
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
    if(s2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(s2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(s2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(s2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(s2.attack(targetFortress) == false){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    // test same team
    s2.setColor("red");
    targetDog->setColor("red");
    targetMice->setColor("red");
    targetElephant->setColor("red");
    targetFortress->setColor("red");
    targetSoldier->setColor("red");
    cout << "Test same color" << endl;
    if(s2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(s2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(s2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(s2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(s2.attack(targetFortress) == false){
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
void TestSoldier:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Soldier()
}

void TestSoldier::testColor(){
    cout << "Test color" << endl;
    Soldier s3;
    // test default color
    if(s3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    s3.setColor("red");
    if(s3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    s3.setColor("blue");
    if(s3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
