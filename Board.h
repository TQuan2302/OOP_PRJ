//Class define the board in the game and index of each piece in the board
#ifndef __BOARD_H__
#define __BOARD_H__

struct Board{
    static int index[7][9];

    static void loadIndex();//Load the position of pieces if use clock on "Load Game"
    static void saveIndex();//Save the index of pieces if user quit the game
    static void makeNewBoard();//Reset the position of pieces if user click on "New Game"
    static bool checkEmpty();//Check if the text file with position of pieces is empty, if not then load a new game
    static void clearIndex();//Clear the position of all pieces. 
};

#endif