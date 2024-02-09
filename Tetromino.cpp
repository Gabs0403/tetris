// File: Tetromino.cpp
// class: COP 3003 Programming II
// Author: Gabriel Correa
// Description: implementation of an abstract Tetromino shape
//--------------------------------------------------------------------------

#include "Tetromino.h"


// Constructors/ Destructors
//---------------------------------------------------------------------------
/**
 * default constructor - set properties to empty
 * */
Tetromino::Tetromino() {
    _shapeType = SHAPE_NONE;
    // all properties are objects with their own default constructors
}
/**
 * property constructor - set the properties to empty
 * @param rows - initialize the rows for the matrix
 * @param columns - initialize the columns for the matrix
 * */
Tetromino::Tetromino(int rows, int columns)
        : Matrix{rows, columns}

        {
    _shapeType = SHAPE_NONE;
}
/**
 * property constructor - set the properties to empty
 * @param rows - initialize the rows for the matrix
 * @param columns - initialize the columns for the matrix
 * @param blocks - initialize the property list in the matrix property constructor
 * */
Tetromino::Tetromino(int rows, int columns, int *blocks)
        :   Matrix{rows,columns, blocks}

{
    _shapeType = SHAPE_NONE;
    // other properties are objects with their own default constructors
}

//Acessors
//--------------------------------------------------------------------------

Tetromino::ShapeType Tetromino::getShapeType() {
    return _shapeType;
}

void Tetromino::setSize(sf::Vector2f size) {
    _size = size;
}

sf::Vector2f Tetromino::getSize() {
    return _size;
}

void Tetromino::setPosition(sf::Vector2f position) {
    _position = position;
}

sf::Vector2f Tetromino::getPosition() {
    return _position;
}

void Tetromino::setFillColor(sf::Color color) {
    _fillColor = color;
}

sf::Color Tetromino::getFillColor() {
    return _fillColor;
}


//Methods
//---------------------------------------------------------------------------

/**
 * draw the Tetromino by going through the Matrix and
 * creating a Rectangle Shape, sizing, positioning, and
 * filling its color, for any cells with a 1
 * @param window - target window to draw on
 * */

void Tetromino::draw(sf::RenderWindow &window) {
    //Calculate block size relative to size of
    //Tetromino and Matrix rows & columns

    sf::Vector2f blockSize {_size.x/_columns, _size.y/_rows};

    // start block position at top left of Tetromino
    sf::Vector2f blockPos = _position;

    for(int row=0;row<_rows;++row){
        blockPos.x = _position.x;

        for(int col = 0; col < _columns; ++col){
            // see if cell in Matrix has 1 in it
            if(hasBlock(row,col)){
                // create temp block, position, and color it

                sf::RectangleShape block{blockSize};
                block.setPosition(blockPos);
                block.setFillColor(_fillColor);
                window.draw(block);

            }
            blockPos.x += blockSize.x;
        } // for column

        blockPos.y += blockSize.y;
    } //for row

} // end draw

/**
 * Rotate this shape counter-clockwise 90 degrees
 * */

void Tetromino::rotate() {
    anticlockwise();
} // end rotate

/**
 * Move a Tetromino one block left, right, or down, no collision
 * checking is done here, so this should only be called if it is
 * possible to move in the direction given
 * @param direction - move shape in given direction
 * @param blocks - the number of blocks to move
 * */

void Tetromino::move(Tetromino::Movement direction,int blocks) {
    switch(direction){
        case MoveLeft:
            _position.x -= (_size.x/_columns)*blocks;
            break;
        case MoveRight:
            _position.x += (_size.x/_columns)*blocks;
            break;
        case MoveDown:
            _position.y += (_size.y/_rows)*blocks;
    }
}

/**
 * @return string representation of the matrix
 * */

std::string Tetromino::toString() {
    std::stringstream ssShape;

    ssShape <<"Tetromino:\n";
    ssShape << +"    Size: (" << int(_size.x)<<","<< int(_size.y) << ")\n";
    ssShape << +"Position: (" << int(_position.x)<<","<<int(_position.y)<<")\n";
    ssShape << +"   Color: (" << int(_fillColor.r)<<","<<int(_fillColor.g)<<","<<int(_fillColor.b)<<")\n";
    ssShape << "  Matrix: \n";
    ssShape << Matrix::toString()<<std::endl;

    return ssShape.str();
}







