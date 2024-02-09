// File: Tetromino.h
// class: COP 3003 Programming II
// Author: Gabriel Correa
// Description: Header file for an abstract shape representing one
//              of the shapes in a Tetris game. Each shape is made
//              up of multiple rectangles used to display the shape.
//              Internally the Tetromino maintains a Matrix of 0's
//              and 1's to represent where graphical shapes should
//              be drawn, based on the top-left corner of this shape
//--------------------------------------------------------------------------

#ifndef TETRIS_TEST_TETROMINO_H
#define TETRIS_TEST_TETROMINO_H


#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include <string>
#include <sstream>

class Tetromino : public Matrix{ //tetromino class will be able to use all properties and methods of Matrix class (except private)
public:
    // colors of the shapes
    static const unsigned int LIGHT_BLUE = 0xADD8E6FF;
    static const unsigned int DARK_BLUE = 0x00008BFF;
    static const unsigned int ORANGE = 0xFFA500FF;
    static const unsigned int YELLOW = 0xFFFF00FF;
    static const unsigned int GREEN = 0x00FF00FF;
    static const unsigned int RED = 0xFF0000FF;
    static const unsigned int MAGENTA = 0xFF00FFFF;
    static const unsigned int CYAN = 0x00FFFFFF;

    // tetromino shape types
    enum ShapeType{
        SHAPE_NONE = -1,
        SHAPE_I,
        SHAPE_J,
        SHAPE_L,
        SHAPE_O,
        SHAPE_S,
        SHAPE_T,
        SHAPE_Z,
        MY_SHAPE,
        SHAPE_COUNT
    };
    // shapes movements
    enum Movement{
        MoveNone,
        MoveLeft,
        MoveRight,
        MoveDown
    };
protected:
    ShapeType _shapeType;

    sf::Vector2f _size;  // (width, height)
    sf::Vector2f _position;// (left,top)
    sf::Color _fillColor;

public:

    // Constructors/ Destructors
    //---------------------------------------------------------------------------

    Tetromino(); // default constructor
    Tetromino(int rows, int columns); //property constructor
    Tetromino(int rows,int columns, int *blocks); //property constructor



    //Acessors
    //--------------------------------------------------------------------------

    ShapeType getShapeType();


    void setSize(sf::Vector2f size);
    sf::Vector2f getSize();

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    void setFillColor (sf::Color color);
    sf::Color getFillColor();

    //Methods
    //---------------------------------------------------------------------------

    void draw(sf::RenderWindow & window);
    void rotate();
    void move(Movement direction,int blocks=1);
    std::string toString();
};




#endif //TETRIS_TEST_TETROMINO_H
