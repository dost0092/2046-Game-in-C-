# 2046-Game-in-C++

Libraries Inclusion:

The code includes necessary C++ libraries such as <conio.h>, <ctime>, <iostream>, and <cmath>.
Game Board Representation:

The game board is represented as a 4x4 matrix a[4][4] where elements are initialized to 0.
i1, i2, i3, and i4 are random indices used to place initial numbers 2 and 4 on the board.
Movement Functions:

The code provides functions like moveup, movedown, leftmove, and rightmove for moving tiles in the corresponding directions.
These functions iterate through the matrix and handle merging of similar tiles and shifting empty spaces.
Block Generation:

The block function generates a new random block (either 2 or 4) at an empty position on the board.
Display Function:

The display function prints the current state of the game board on the console.
It also indicates the control keys for playing and provides an option to quit the game using the Escape key.
Game Logic:

The main game loop runs indefinitely until the player chooses to exit the game (by pressing the Escape key).
Inside the loop, the code listens for arrow key inputs using _getch().
Depending on the key pressed, the corresponding movement function is called.
If the board changes after a move, a new block is generated, and the updated board is displayed.
Game Termination:

The game loop breaks when the player presses the Escape key (ch == 27), ending the game.
Note:

The code utilizes low-level console input functions (_getch()) for simplicity. In modern C++, you might use different input methods for a more user-friendly experience.
Overall, the code creates a simple console-based implementation of the 2048 game, allowing players to move tiles and merge numbers until they decide to quit the game.
