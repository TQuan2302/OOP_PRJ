//Implementation of GameMove.h
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "GameMove.h"
#include "GameProperty.h"

using namespace std;

bool GameMove::turn = true; // red = true, blue = false;

// get possible move and push in the vector
void GameMove::characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn){
    // true = red, false = blue
    bool validColor = currentBoard.index[current_X][current_Y] < 8;
    // check 4 directions to get possible move
    if (currentBoard.index[current_X][current_Y] > -1 && currentBoard.index[current_X][current_Y] < 16 && validColor == turn){
        // if x-axis > 0, push_back x-1
        if(current_X>0){
            possibleMoves.push_back(Move(current_X, current_Y, current_X-1, current_Y));
        }
        // if x-axis < 7, push_back x+1
        if(current_X<7){
            possibleMoves.push_back(Move(current_X, current_Y, current_X+1, current_Y));
        }
        // if y-axis > 0, push_back y-1
        if(current_Y>0){
            possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y-1));
        }
        // if y-axis < 9, push_back y+1
        if(current_Y<9){
            possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y+1));
        }
    }
}
// search all board to get possible move
vector<Move> GameMove::getLegalMoves(Board currentBoard, bool turn){
    vector<Move> possibleMoves;
    // use nested for-loop to get possible move 
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 9; ++j){
            if(currentBoard.index[i][j] > -1 && currentBoard.index[i][j] < 16){
                characterMove(possibleMoves, i, j, turn);
            }
        }
    }
    return possibleMoves;
}
// compute move
bool GameMove::playMove(Move newMove, Character* aimPiece, Character* choosePiece){
    // get all possible move
    vector<Move> possibleMoves = getLegalMoves(currentBoard, turn);
    Move temp;
    // for-loop to check all possible moves
    for (int i = 0; i < possibleMoves.size(); i++){
        temp = possibleMoves[i];
        // if the move matches a possible move -> move
        if (temp.old_X == newMove.old_X && temp.old_Y == newMove.old_Y && temp.new_X == newMove.new_X && temp.new_Y == newMove.new_Y){
            // check if it is a attack
            if(choosePiece->attack(aimPiece) && choosePiece->getColor() != aimPiece->getColor()){ // attack
                killMessage(aimPiece); // show message when attacking
                // if the captured pieace is a fortress or soldier
                if(aimPiece->getName() == "fortress" || aimPiece->getName() == "soldier"){
                    // destroy both 2 pieces
                    currentBoard.index[newMove.new_X][newMove.new_Y] = -1;
                    currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                    disappear = true;
                    GameProperty::sounds[5].play(); 
                }
                // if the captured pieace is an animal          
                else{
                    // move piece
                    currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
                    currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                    disappear = false;
                    GameProperty::sounds[1].play();
                }
                return true;
            }
            // if it is a move to a new place
            else if(currentBoard.index[newMove.new_X][newMove.new_Y] == -1){
                // move piece
                currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
                currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                disappear = false;
                GameProperty::sounds[0].play();
                return true;
            }
        }
    }
    // wrong move 
    GameProperty::showWrongMove = true;
    disappear = false;
    return false;
}

void GameMove::killMessage(Character* killPiece){//Display the window with announcement of "SUCCESSFULL KILL" enemy piece if the attack if valid
    RenderWindow killWin(sf::VideoMode(410, 80), "SUCCESSFULL KILL"); //to do 
    while(killWin.isOpen()){//Main Loop
        Event killEvent;
        while(killWin.pollEvent(killEvent)){
            if(killEvent.type == Event::Closed){
                killWin.close();
                break;
            }
        }
        //Create a font and text message for the text in the message
        Font font;
        Text text;
        killWin.clear(Color::White);// Clear the window with white color
        string kill;
        kill = killPiece->getColor() + " " + killPiece->getName() + " is killed!"; //Content of the text in the window
        text.setString(kill);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");//Load the font into the Font object 
        text.setFont(font); //Set the Font of the text, 
        text.setFillColor(Color::Black);//Set the fill color of the text to Black
        text.setCharacterSize(30);//Set the text size
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(killWin.getSize().x / 2.0f,  // Center horizontally
                        killWin.getSize().y / 2.0f); // Center vertically
        killWin.draw(text);//Draw the text 
        killWin.display();//Display the text
    }
}
// switch turn
bool GameMove::nextTurn(){
    turn = !turn;
    return turn;
}
// getter
bool GameMove::getTurn(){
    return turn;
}

void GameMove::saveTurn(){
    // The string to be written to the file
    std::string content = "red";

    if(turn == false){
        content = "blue";
    }

    // Create an output file stream
    std::ofstream file("./Assets/Text/turn.txt");

    // Write the string to the file
    file << content;

    // Close the file
    file.close();
    
}

void GameMove::loadTurn(){
    // Create an input file stream
    std::ifstream file("./Assets/Text/turn.txt");

    // Variable to hold the file content
    std::string fileContent;
    std::string line;

    // Read file line by line and append to fileContent
    while (std::getline(file, line)) {
        fileContent += line;  // Append line and newline
    }

    // Close the file
    file.close();

    if(fileContent == "red"){
        turn = true;
    }
    else{
        turn = false;
    }
}

void GameMove::resetTurn(){
    // The string to be written to the file
    std::string content = "red";

    // Create an output file stream
    std::ofstream file("./Assets/Text/turn.txt");

    // Write the string to the file
    file << content;

    // Close the file
    file.close();
}
