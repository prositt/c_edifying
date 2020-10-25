#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Box{
    
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solveable;
    struct Box * next;
}  Box;

typedef struct Square {

    int number;
    /*  [0] [0] [0] [0] [0] [0] [0] [0] [0] 
        [9] [8] [7] [6] [5] [4] [3] [2] [1] */
    int possible[9];
    int solveable;
    Box * box;
    int row;
    int col;
} Square;

Square *** setUpPuzzle(int ** puzzle);

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Square *** setUpPuzzle(int ** puzzle);

int solveSquare(Square * square);

int checkPuzzle(Square *** sudoku);
int updateSudoku(Square *** sudoku, int row, int col);

/* box functions*/
int createBoxes();


#endif