#ifndef TEST_ELEPHANT_H
#define TEST_ELEPHANT_H
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

class TestElephant{
    public: 
        void runTestElephant(){
            TestConstructor(); 
            testAttack();
            testDestructor(); 
            testColor();
            testName();
        }
    private:
        void TestConstructor(); 
        void testAttack(); 
        void testDestructor(); 
        void testColor();
        void testName();
};

#endif
