// File: TetrisBoard.h
// class: COP 3003 Programming II
// Author: Gabriel Correa
// Description: header file for the class TetrisBoard
//--------------------------------------------------------------------------
#include "tetris.h"
#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include <random>

#ifndef TETRIS3_TETRISBOARD_H
#define TETRIS3_TETRISBOARD_H


class TetrisBoard {
public:
    // Constructors/ Destructors
    //---------------------------------------------------------------------------

    TetrisBoard(); //default constructor
    ~TetrisBoard(); //destructor

    //Methods
    //---------------------------------------------------------------------------

    bool update(KeyPressedState input[]);
    void render(sf::RenderWindow & window);

private:




    // current and next shape
    Tetromino* _currentShape;
    Tetromino* _nextShape;

    // top/left row/column of the grid for current shape
    sf::Vector2i _currentCell;

    // properties for generating random numbers to select
    // the next Tetromino at random
    //        randomDevice is a seed for the generator
    //        uses a mersene_twister generator engine
    //        produces a uniform integer distribution
    std::random_device _randDevice;
    std::mt19937 _randGenerator;
    std::uniform_int_distribution<> _randDistribution;

    //Methods
    //---------------------------------------------------------------------------

    bool nextShape();
    bool canMove(Tetromino::Movement movement);
    void lockShape();
    bool hasCollision(Tetromino & shape,sf::Vector2i location);
    bool canRotateShape();
    void wallKick(sf::Vector2i & location);


    //structures
    //--------------------------------------------------------------------------

    //for game delays
    struct FrameCounters{
        int newShapeRate;
        int newShape;
        int autoMoveRate;
        int autoMove;
        int numberOfShapes;

    };

    FrameCounters _counters; // track and adjust game delays


    struct GridCell{
        bool is_filled;
        sf::RectangleShape block;
    };
    // grid cells by row and column
    GridCell _cells[GAME_ROWS][GAME_COLUMNS];


};

#endif //TETRIS3_TETRISBOARD_H
