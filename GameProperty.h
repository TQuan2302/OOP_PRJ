// this class contains all functions and variables necessary to lauch the game

#ifndef __GAMEPROPERTY_H__
#define __GAMEPROPERTY_H__

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Player.h"
#include "Animal.h"
#include "Soldier.h"
#include "Fortress.h"
#include "Character.h"
#include "GameMove.h"
#include "Board.h"

using namespace std;
using namespace sf;

class GameProperty
{
private: 
    // main window
    sf::RenderWindow win;
    // initialise 63 shapes on the board
    sf::RectangleShape squares[7][9];
    // define rectangular area for the game board
    sf::IntRect holder;
    // define 3 colors in need for the game
    sf::Color colorsNeed[3];
    // define 63 pieces corresponding to 63 squares on the board
    ChessPiece pieces[63];
    // width and height of the game window
    int width;
    int height;
    // 2 players in a game
    Player* players1;
    Player* players2;
    // animal pieces of both sides
    Animal** redAnimals;
    Animal** blueAnimals;
    // fortress pieces of both sides
    Fortress* redFortress;
    Fortress* blueFortress;
    // soldier pieces of both sides
    Soldier** redSoldiers;
    Soldier** blueSoldiers;
    // initialise a GameClass variable to launch movements in the game
    GameMove moveAnimal;
    // 8 textures for 8 different images on the board
    Texture pieceTexture[8]; 
    // variable to store selected square which helps move the animal. 
    // When moving animals, this is the original position of the animals
    int selectAxis[2]; // == 1, a square is selected
                       // == 0, no square is selected
    bool select = 0; //  to know whether a square is selected 
    // variable to define the reason when the game ends
    int reason = -1; // == -1: no reason
                     // == 1: a fortress is occupied
                     // == 2: all animals in of a side are killed
                     // == 3: no animal on the board -> tied game
    // variable for winner, if this is " ", the game still continues.
    string winner = " ";
public:
    static bool showWrongMove;
    // constructor
    GameProperty(int width, int height, const char* imageFile[8], string gameName);
    // music and sound effects while launching game
    static Music sounds[6]; // move - capture - up - start - end - boom
    // get arrays of characters for 2 players
    void createPlayers();
    // create images and other necessary elements for 63 pieces 
    void createPiece(const char* imageFile[8]);
    // draw 63 squares on the table
    void drawSquares();
    // draw characters on the board
    void drawImage();
    // set sizes of 63 squares on the board
    void setHolders();
    // set position of images on the board
    void mapPieces();
    // set position of images on the board while moving
    void mapPieces(Move moving);
    // function to run the game
    void run();
    // display red or blue turn on the screen to let players know whose turn is
    void displayTurn();
    // check whether the game ends
    string checkWinner();
    // make window to show winner and reason when the game ends
    void showWinner();
    // make help window when press 'H' on the keyboard when playing
    void helpWindow();
    // show message when choosing invalid move
    void wrongMoveMessage();
    // function to start a new game
    void callNewGame(); 
    // destructor
    ~GameProperty(); 
};

#endif