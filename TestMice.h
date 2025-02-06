#ifndef TEST_MICE_H
#define TEST_MICE_H
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

class TestMice{
    public: 
        void runTestMice(){
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
