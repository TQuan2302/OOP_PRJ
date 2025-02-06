#include <iostream>
#include "TestDog.h"
#include "Fortress.h"
#include "Soldier.h"

void TestDog:: TestConstructor(){
    cout << "Test constructor" << endl;
    Dog d0; 
    if(!d0.getName().compare("dog")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    if(d0.getName().compare(" ")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
}
void TestDog::testName(){
    Dog d1; 
    cout << "Test setName() and getName()" << endl;
    d1.setName("aaa"); 
    if(!d1.getName().compare("aaa")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
    d1.setName(" "); 
    if(!d1.getName().compare(" ")){
        cout << "setName() passed" << endl; 
    }
    else{
        cout << "setName() failed" << endl; 
    }
}
void TestDog:: testAttack(){
    Dog d2; 
    // test different team
    d2.setColor("red");
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
    if(d2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(d2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(d2.attack(targetMice) == true){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(d2.attack(targetSoldier) == true){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(d2.attack(targetFortress) == true){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    // test same team
    d2.setColor("red");
    targetDog->setColor("red");
    targetMice->setColor("red");
    targetElephant->setColor("red");
    targetFortress->setColor("red");
    targetSoldier->setColor("red");
    cout << "Test same color" << endl;
    if(d2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(d2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(d2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    if(d2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(d2.attack(targetFortress) == false){
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
void TestDog:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Dog()
}
void TestDog::testColor(){
    cout << "Test color" << endl;
    Dog d3;
    // test default color
    if(d3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    d3.setColor("red");
    if(d3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    d3.setColor("blue");
    if(d3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
