// File: tetris.cpp
// class: COP 3003 Programming II
// Author: Gabriel Correa
// Description: main application file for a tetris game
//--------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include "tetris.h"
#include "TetrisBoard.h"



//functions declarations
//----------------------------------------------------------------------
bool processEvents(sf::RenderWindow & window,KeyPressedState input[]);
bool update(KeyPressedState input[],TetrisBoard & board);
void render(sf::RenderWindow & window , TetrisBoard & board);


//functions definitions
//----------------------------------------------------------------------


int main() {
    //create the game window width x height with title
    sf::RenderWindow window {sf::VideoMode(WIN_WIDTH,WIN_HEIGHT),"Tetris"};

    //game board grid for the Tetris game
    TetrisBoard gameboard;

    //keyboard state handling
    KeyPressedState keyStates[sf::Keyboard::KeyCount] = {0};



    //update frame timing
    //---------------------------------------------------------------------------------------------
    sf::Clock frameTimer; // frame rate timer
    int lag{0};          // cumulative lag time each frame


    bool gameover = false;

    // main game loop
    while(!gameover){

        lag += frameTimer.restart().asMilliseconds();
        gameover = processEvents(window,keyStates);

        //wait until we get to a frame boundary to update
        while(lag>= FRAME_RATE_MS){

            gameover = update(keyStates,gameboard);

            lag -=FRAME_RATE_MS; // reduce lag by 1 frame
        }

        render(window,gameboard);


    }  // end of main game loop

    sf::Font font;
    font.loadFromFile("Roboto-Medium.ttf");
    sf::Text gameOverText("Game Over", font, 50); // Create text object with size 50
    gameOverText.setFillColor(sf::Color::Cyan); // Set text color
    gameOverText.setStyle(sf::Text::Bold); // Set text style

    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setPosition(WIN_WIDTH / 2 - textBounds.width / 2,
                             WIN_HEIGHT / 2 - textBounds.height / 2);

    // Render "Game Over" message
    window.draw(gameOverText);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
} //end main

/**
 * process window and keyboard events
 * @param window - reference to the main window
 * @param input  - prior and current state of each keyboard key
 * @return true*= window closing
 * */

bool processEvents(sf::RenderWindow & window,KeyPressedState input[]){
    bool closing = false;


    sf::Event event;
    while(window.pollEvent(event))
    {
        //check for close request
        if(event.type == sf::Event::Closed){
            closing = true; // return closing true
        }
            //check for keyboard events
            // only watching for key being released
        else if( event.type == sf::Event::KeyReleased){
            // if key's prior state is off
            if(!input[event.key.code].prior){
                //set current and prior state on
                // will be turned off in update

                input[event.key.code].current = true; // detected this loop
                input[event.key.code].prior = true; // ignore next loop
            }
        }



    } // while events
    return closing;
} // end process events

/**
 * update state of game objects each frame
 * @param input - keyboard input
 * @param shape - shape to update
 * @return true if game should end
 * */

bool update(KeyPressedState input[],TetrisBoard & board){
    bool endgame;

    // update objects on the game board
    endgame = board.update(input);

    return endgame;
} // end update

/**
 * draw shapes on the main window
 * @param window - reference to the main window
 * @param board - main game board
 * */

void render(sf::RenderWindow & window, TetrisBoard & board){
    window.clear(BACKGROUND_COLOR);

    //draw the game board grid
    board.render(window);

    window.display();


} // end render




