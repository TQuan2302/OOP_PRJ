//Class for button include some functions to draw the button to the window and change the state of the button depend on user mouse in the intro window. 
#ifndef BUTTON_H
#define BUTTON_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std; 
using namespace sf; 

enum ButtonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE }; //Data member for the state of the button 
//BTN_IDLE: When the mouse does not interact with the button
//BTN_HOVER: When the mouse hover the button 
//BTN_ACTIVE: When the user click on the button 

class Button{
    private:
        //the shape of button, font of text and the content of the button 
        RectangleShape shape;
        Font* font; 
        Text text; 
        //3 colors represent 3 states of buttons
        Color idleColor; //Idle state (When user does not click or hover it)
        Color hoverColor; //Hover state (When user Hover)
        Color activeColor; //Active State (When user click on it)
        //Represent state of button
        ButtonStates buttonState;
        
    public:
        Button(float x, float y, float width, float height, string text, Font* font, Color idleColor, Color hoverColor, Color activeColor);
        ~Button(); 

        //Function:
        void render(RenderTarget* target);  //Draw the target into window
        void update(Vector2f mousePos); //Change the state of buttons if user click, hover or take no action if user does nnot click on it 
        ButtonStates getButtonStates(); //Return the state of the button 

};

#endif