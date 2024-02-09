// file: MyShape.h
// class: COP 3003 Programming II
// by: Gabriel Correa
// description: Z shape for game tetris derived from the base class tetromino
//-------------------------------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>


#ifndef TETRIS3_MYSHAPE_H
#define TETRIS3_MYSHAPE_H


class MyShape : public Tetromino{ //MyShape will be able to use properties and methods from Tetromino class( except private)
private:



public:
    explicit MyShape(sf::Vector2f position={0.f,0.f})
    :Tetromino(3,3){ // init rows and columns to 3x3
    // set the shape type
    _shapeType = MY_SHAPE;

    // define the matrix values
    int blocks[9] = {1,1,1,1,0,1,0,0,0};

    // set the internal matrix
    setMatrix(blocks);

    // set the screen size, position, and color
    _size = sf::Vector2f (_rows*BLOCK_SIZE,_columns*BLOCK_SIZE);
    _position = position;
    _fillColor = sf::Color(CYAN);
} // default constructor




};


#endif //TETRIS3_MYSHAPE_H
