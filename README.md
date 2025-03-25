# Tetris Game

[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/Gabs0403/tetris/badge)](https://securityscorecards.dev/viewer/?uri=github.com/Gabs0403/tetris)



This Tetris game was developed as part of my **Programming II** class. It is a classic block-stacking puzzle game where the player must arrange falling shapes to complete full rows and earn points.

## Features

- **Shape Movement**: Move shapes left, right, and down.
- **Rotation**: Rotate shapes to fit them into place.
- **Next Shape Preview**: See the upcoming shape to plan ahead.
- **Increasing Difficulty**: The game speeds up as the player advances.

## Future Improvements

- **Row Clearing**: When a row is filled, it should disappear, and the blocks above should move down.
- **Enhanced UI**: Improve the visual appeal of the game.
- **Sound Effects**: Add sound effects for actions like rotating, clearing rows, and game over.

## Installation

To set up the project, first, clone the repository using `git clone https://github.com/Gabs0403/tetris.git` and navigate to the project folder. 
Ensure you have a C++ compiler installed: on Windows, use MinGW or Visual Studio; on Mac, install Xcode Command Line Tools (`xcode-select --install`); on Linux, install g++ (`sudo apt install g++`). 
Next, install **SFML**: download it from [SFML](https://www.sfml-dev.org/download.php) for Windows, use Homebrew (`brew install sfml`) on Mac, or install it on Linux via `sudo apt-get install libsfml-dev`. 
Once dependencies are installed, compile the project by running `g++ -o tetris main.cpp -lsfml-graphics -lsfml-window -lsfml-system` in the terminal, then execute `./tetris` to start the game.





