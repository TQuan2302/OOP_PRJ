#include <iostream>
#include "TestMove.h"
#include "Move.h"

using namespace std;

void TestMove::testDefaultConstructor(){
    cout << "Test default constructor" << endl;
    Move m1;
    if(m1.new_X == -1 && m1.new_Y == -1 && m1.old_X == -1 && m1.old_Y == -1){
        cout << "Test passed, default constructor is built" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
}

void TestMove::testConstructor(){
    cout << "Test parameterized  constructor" << endl;
    // test positive numbers
    Move m2(1, 2, 3, 4);
    if(m2.old_X == 1 && m2.old_Y == 2 && m2.new_X == 3 && m2.new_Y == 4){
        cout << "Test passed, parameterized  constructor is built" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
    // test negative numbers
    Move m3(-3, -3, -3, -3);
    if(m3.old_X == -3 && m3.old_Y == -3 && m3.new_X == -3 && m3.new_Y == -3){
        cout << "Test passed, parameterized  constructor is built" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
    // test mix
    Move m4(-9, 0, 9999, 34);
    if(m4.old_X == -9 && m4.old_Y == 0 && m4.new_X == 9999 && m4.new_Y == 34){
        cout << "Test passed, parameterized  constructor is built" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
}