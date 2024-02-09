// file: ShapeI.h
// class: COP 3003 Programming II
// by: Gabriel Correa
// description: I shape for game tetris derived from the base class tetromino
//-------------------------------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>


#ifndef TETRIS3_SHAPEI_H
#define TETRIS3_SHAPEI_H


class ShapeI : public Tetromino{ //ShapeI will be able to use properties and methods from Tetromino class( except private)
private:



public:
    explicit ShapeI(sf::Vector2f position={0.f,0.f})
    :Tetromino(4,4){ // init rows and columns to 4x4
        // set the shape type
    _shapeType = SHAPE_I;

    // define the matrix values
    int blocks[16] = {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0};

    // set the internal matrix
    setMatrix(blocks);

    // set the screen size, position, and color
    _size = sf::Vector2f (_rows*BLOCK_SIZE,_columns*BLOCK_SIZE);
    _position = position;
    _fillColor = sf::Color(LIGHT_BLUE);
}



};


#endif //TETRIS3_SHAPEI_H
