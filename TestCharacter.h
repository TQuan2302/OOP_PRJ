#ifndef TEST_CHARACTER_H
#define TEST_CHARACTER_H
#include "Character.h"

class TestCharacter{
    public: 
        void runTestCharacter(); 
    private: 
        void testDefaultContructor(); 
        void testParameterizedConstructor(); 
        void testGetName(); 
        void testSetName(); 
        void testGetColor(); 
        void testSetColor(); 
        void testAttack(); 
};
    

#endif