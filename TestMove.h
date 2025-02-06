#ifndef TESTMOVE_H
#define TESTMOVE_H
#include <iostream>

using namespace std;

class TestMove
{
private:
    void testDefaultConstructor();
    void testConstructor();
public:
    void runTestMove(){
        testDefaultConstructor();
        testConstructor();
    }
};

#endif