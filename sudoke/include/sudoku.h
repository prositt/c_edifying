#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Sudoku{
    struct Square *** squares;
    struct Box ** boxes;
} Sudoku;

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


int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Sudoku * setUpPuzzle(int ** puzzle);

Sudoku * createSudoku(Square *** sudoku, Box ** boxes);

int updateSudoku(Square *** sudoku, int row, int col);
int checkPuzzle(Square *** sudoku, Box ** boxes);

int solveSquare(Square * square);

int boxSingles(Square *** sudoku, Box ** boxes);


void printSquare(Square * square);



/* box functions*/
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);


#endif