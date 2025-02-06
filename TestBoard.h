#ifndef __TESTBOARD_H__
#define __TESTBOARD_H__
#include <iostream>
#include "Board.h"

using namespace std;

class TestBoard
{
public:
    void runTestBoard(){
        testEmpty();
        testNewBoard();
        testSaveIndex();
    }
private:
    void testEmpty();
    void testNewBoard();
    void testSaveIndex();
};

#endif