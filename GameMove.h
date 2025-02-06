//Class define the main part of the game include: Drawing a chess board, check who is the winner, 
//Calculate all legal move and allow user to move a piece
#ifndef __GAMEMOVE_H__
#define __GAMEMOVE_H__

#include <vector>
#include <iostream>
#include "Board.h"
#include "Move.h"
#include "ChessPiece.h"

using namespace std;

class GameMove{
private:
    static bool turn; // red = true, blue = false;
    Board currentBoard;
public:
    bool disappear = false;
    void characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn);
    bool playMove(Move newMove, Character* aimPiece, Character* choosePiece);
    static bool nextTurn();
    vector<Move> getLegalMoves(Board currentBoard, bool turn);
    // getter
    bool getTurn();
    //Display a message indicates that a piece is killed
    void killMessage(Character* killPiece);
    //Save the turn when user quit the game
    static void saveTurn();
    //Load the turn when user load the game
    static void loadTurn();
    //Reset turn to red team if user resets the game
    static void resetTurn();
};

#endif