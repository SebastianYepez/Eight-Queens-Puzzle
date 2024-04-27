// PROGRAM BY SEBASTIAN YEPEZ, Feb 2024

// EIGHT QUEENS PUZZLE

// IMPORT LIBRARIES
#include <iostream>

// DECLARE NAMESPACE
using namespace std;

// CONSTANTS
const int BOARD_SIZE = 28; // change to make any n x n board 31 > n > 3

// FUNCTION PROTOTYPES
void initializeBoard(char b[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char b[BOARD_SIZE][BOARD_SIZE]);
bool findSpace(int x1, int x2, char board[BOARD_SIZE][BOARD_SIZE], int numQueens);
bool checkSafe(int x1, int x2, char board[BOARD_SIZE][BOARD_SIZE]);

// MAIN
int main()
{
    // BOARD_SIZE is static and determined by the programmer in the const value above
    if (BOARD_SIZE < 4) {
        cerr << "Error: Board Size is too small (Programmer Bug)" << endl;
        return 1;
    }
    else if (BOARD_SIZE > 30) {
        cerr << "Error: Board Size is too large - would take too long" << endl;
        return 1;
    }
    else if(BOARD_SIZE > 21) {
        cout << "Board size is relatively large. This may take a while . . ." << endl;
    }

    char chessboard[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(chessboard);

    int coord1, coord2 = 0;

    // validates starting square
    while (true)
    {
        cout << "Enter initial coordinates of the first queen: ";
        cin >> coord1 >> coord2;
        if (coord1 > 0 && coord2 > 0)
        {
            if (coord1 <= BOARD_SIZE && coord2 <= BOARD_SIZE)
            {
                break;
            }
        }
        cout << "Invalid Input. Please input a set of coords with values 1 - " << BOARD_SIZE << endl;
    }

    cout << coord1 << " " << coord2 << endl;
    cout << endl;

    chessboard[coord1 - 1][coord2 - 1] = 'Q';

    bool gameOver = false;
    while (!gameOver)
    {
        gameOver = findSpace(coord1 - 1, coord2 - 1, chessboard, 1);
    }
}

// RECURSIVE FUNCTION

bool findSpace(int x1, int x2, char board[BOARD_SIZE][BOARD_SIZE], int numQueens)
{
    if (numQueens == BOARD_SIZE)
    {
        printBoard(board);
        return true; // WIN CONDITION: 8x8 board -> 8 Queens
    }

    char newboard[BOARD_SIZE][BOARD_SIZE];

    // create new copy of the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            newboard[i][j] = board[i][j];
        }
    }

    int currRow = 0; // starts at (1, 1)
    int currCol = 0;
    bool spaceFound = false;
    while (!spaceFound)
    {
        // checks to see if the row is safe
        bool safeRow = false;
        while (!safeRow)
        {
            safeRow = true;
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[currRow][j] != '-')
                {
                    currRow++; // goes to the next row
                    safeRow = false;
                }
            }
        }
        spaceFound = checkSafe(currRow, currCol, newboard);
        if (spaceFound)
        {
            // if a safe spot is found on the row:
            newboard[currRow][currCol] = 'Q'; // place a queen on this spot
            if (findSpace(currRow, currCol, newboard, ++numQueens))
            {
                return true;
            } // try the next row
            else
            {
                newboard[currRow][currCol] = '-';
                numQueens--;
                spaceFound = false;
            }
        }
        currCol++;
        if (currCol == BOARD_SIZE)
        { // if all columns were checked
            break;
        }
    }
    return false;
}

// function that checks whether the location at board[x1][x2] is safe to place a queen
bool checkSafe(int x1, int x2, char board[BOARD_SIZE][BOARD_SIZE])
{
    // row is already checked in findSpace()

    // check the column
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][x2] != '-')
            return false; // iterates through col
    }

    // check upper left diagonal
    int tempR = x1;
    int tempC = x2;
    while (tempR >= 0 && tempC >= 0)
    {
        if (board[tempR][tempC] != '-')
            return false;
        tempR--;
        tempC--;
    }

    // check upper right diagonal
    tempR = x1;
    tempC = x2;
    while (tempR >= 0 && tempC < BOARD_SIZE)
    {
        if (board[tempR][tempC] != '-')
            return false;
        tempR--;
        tempC++;
    }

    // check lower right diagonal
    tempR = x1;
    tempC = x2;
    while (tempR < BOARD_SIZE && tempC < BOARD_SIZE)
    {
        if (board[tempR][tempC] != '-')
            return false;
        tempR++;
        tempC++;
    }

    // check lower left diagonal
    tempR = x1;
    tempC = x2;
    while (tempR < BOARD_SIZE && tempC >= 0)
    {
        if (board[tempR][tempC] != '-')
            return false;
        tempR++;
        tempC--;
    }

    // if row, col, and 4 diagonals are safe -> spot is safe
    return true;
}

// initializes the chess board so that all spaces are filled with a "-"
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
}

// prints the values stored within the chessboard
void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    // prints numbers 1 - n on row 0
    for (int i = 0; i <= BOARD_SIZE; i++)
    {
        if (i == 0)
        {
            cout << "   "; // accounts for "#   " on column
            if (BOARD_SIZE > 9)
                cout << " ";
            continue;
        }
        cout << i << "  ";
        if (BOARD_SIZE > 9 && i < 10) cout << " ";
    }
    cout << endl;

    // prints values stored within array indexes
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // prints numbers 1 through n on first column
            if (j == 0)
            {
                cout << i + 1 << "  ";
                if (BOARD_SIZE > 9 && i < 9)
                    cout << " ";
            }
            // prints current element
            cout << board[i][j] << "  ";
            if (BOARD_SIZE > 9)
                cout << " ";
            // if at end of row -> print space
            if (j == BOARD_SIZE - 1)
                cout << endl;
        }
    }
}
