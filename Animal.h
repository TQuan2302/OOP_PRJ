// abstract class animal which contains animals in the game, derived from Character class.
#ifndef ANIMAL_H
#define ANIMAL_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Character.h"
#include "ChessPiece.h"

using namespace std; 
using namespace sf;

class Animal:public Character
{
public:
    // constructor
    Animal(string name); 
    // default constructor
    Animal(); 
    // pure virtual function to make abstract class animal
    bool attack(Character* piece) = 0; 
    // destructor
    ~Animal(); 
};

#endif
