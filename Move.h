//Class define move for pieces in the game.
// define struct move
#ifndef __MOVE_H__
#define __MOVE_H__

struct Move{
    int old_X, old_Y, new_X, new_Y;
    Move();
    Move(int old_X, int old_Y, int new_X, int new_Y);//Constructor for a move object, called whenever user make a legal move.  
};

#endif
