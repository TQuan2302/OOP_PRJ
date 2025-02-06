#include<iostream>
#include "TestDog.h"
#include "TestMice.h"
#include "TestElephant.h"
#include "TestFortress.h"
#include "TestSoldier.h"

int main(){
    //Test Dog class: 
    cout << "Test Dog Class" << endl ;
    TestDog test1; 
    test1.runTestDog(); 

    //Test Mice class: 
    cout << endl; 
    cout << "Test Mice Class" << endl ;
    TestMice test2; 
    test2.runTestMice(); 

    //Test Elephant class: 
    cout << endl; 
    cout << "Test Elephant Class" << endl ;
    TestElephant test3; 
    test3.runTestElephant(); 

    //Test Fortress:
    cout << endl; 
    cout << "Test Fortress Class" << endl; 
    TestFortress test4; 
    test4.runTestFortress(); 

    //Test Soldier:
    cout << endl; 
    cout << "Test Soldier Class" << endl; 
    TestSoldier test5; 
    test5.runTestSoldier();
    return 0;
}