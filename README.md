# TetrisVS
Term work for second semester Program Engineering at VGTU.

## Game

It is a simple game of tetris, where a player can take on another player or choose to compete against a computer player.

The control schemes are stored in `/build/data/schemes` and are structured as follows:

* LEFT
* RIGHT
* DOWN
* DROP
* CLOCKWISE ROTATE
* COUNTERCLOCKWISE ROTATE
* HOLD

## AI

The artificial intelligence is done with a hardcoded values for specific heuristics, trained by a neural network.

Thanks to [Yiyuan Lee](https://codemyroad.wordpress.com/author/leeyiyuan/) who has shared the heuristics and the values of a great AI for Tetris.

You can read and find information regarding the heuristics and values used here: [Tetris AI – The (Near) Perfect Bot](https://codemyroad.wordpress.com/2013/04/14/tetris-ai-the-near-perfect-player/).

## Building

This game uses the `PDCurses` library.
 
You have to build `wincon`.

Link `wincon` with `PDCurses`.

Finally, build `curses` library, linking `PDCurses` against it.

To build the game, you link the `curses` library against `tetrisvs`.