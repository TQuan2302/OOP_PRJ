#ifndef __CHESSPIECE_H__
#define __CHESSPIECE_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"

using namespace std;
using namespace sf;

struct ChessPiece
{
    int pieceID;
    int x;
    int y;
    bool draw = 0;
    Sprite image;
    Character* character; 
};

#endif