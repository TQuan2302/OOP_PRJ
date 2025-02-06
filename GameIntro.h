#ifndef GAME_INTRO_H
#define GAME_INTRO_H
#include<iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf; 
using namespace std; 

class GameIntro{
    private:
        RenderWindow introWindow; //Object for the intro window
        Font font; //Object for the Font of text
    public:
        GameIntro(); //Constructor for the Intro. 
        void closeWindow();  //Getter for introWindow. 
        static bool showInstruction;
        static void openRuleWindow(Font font); 
        static void finalMessage(); //Display the window with final message if the user quit the gagme
        static void playIntroMusic(); //Play music when the intro window pops up. 
        static const char* imageFile[8]; // file paths to images of animals, fortresses and soldiers
}; 

#endif