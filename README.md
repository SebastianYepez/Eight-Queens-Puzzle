# Eight-Queens-Puzzle

## Description
In chess, a queen can attack in any direction: horizontally, vertically, or diagonally. Therefore, the goal of the Eight Queens Puzzle is to arrange the queens in such a manner that no two queens share the same row, column, or diagonal. This program utilizes recursion in order to determine the first possible arrangement of queens based on a user-input initial starting square. What makes this program unique, however, is that the board size is not limited to 8 x 8! Feel free to solve this dilemma on a 15 x 15 board.

## Functionality
This program utilizes a backtracking algorithm through the use of recursion in order to determine the first possible arrangement of the n number of queens based on a user-input initial starting square

## Usage
If desired, one could adapt the code so that the board size could be determined by the user during runtime, but they would have to utilize a dynamic array in order to achieve this implementation.

## Limitations
The size is limited to 31 > n > 4 as a board smaller than 4 x 4 would be unsolvable, and a board greater than size 30 x 30 would take so long due to the time complexity of such algorithms.

## Have Fun!
Feel free to experiment with different board sizes and starting positions for the initial queen!
