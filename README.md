# Eight-Queens-Puzzle

## Description
The Eight Queens Puzzle is a chess board dilemma in which the objective is to place eight queens on an 8 x 8 chessboard in such a manner that no two queens threaten each other. In this implementation, I've added a twist: the programmer can adjust the board size during compilation, offering flexibility in solving the puzzle.

## Functionality
This program utilizes a backtracking algorithm through the use of recursion in order to find the first possible "path" of which the n number of queens can be placed.

## Usage
If desired, one could adapt the code so that the board size could be determined by the user during runtime, but they would have to utilize a dynamic array in order to achieve this implementation.

## Limitations
The size is limited to 31 > n > 4 as a board smaller than 4 x 4 would be unsolvable, and a board greater than size 30 x 30 would take so long due to the time complexity of such algorithms.

## Have Fun!
Feel free to experiment with different board sizes and starting positions for the initial queen!
