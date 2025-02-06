// the implementation of "Character.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "ChessPiece.h"

using namespace std;
using namespace sf;

// default constructor, assign empty string to name 
Character::Character():Character(" "){}

// constructor, with input name
Character::Character(string name):name(name){}

// getter
string Character::getName(){
    return name;
}
string Character::getColor(){
    return color;
}
// setter
void Character::setName(string name){
    this->name = name;
}
void Character::setColor(string color){
    this->color = color;
}

// the function is overriden by the derived classes
// by default, this function return false
bool Character::attack(Character* aimPiece){
    return false;
}

// destructor
Character::~Character(){
}