#include "sudoku.h"

int solveSquare(Square * square){
    int x;

    for (x = 0; x < SIZE_ROWS; x++){
        if(square-> possible[x] == 0){
            square->number = x+1;
            square->solveable = 0;
            UNSOLVED--;
        }
    }
    printf("Solved ->\t");
    printSquare(square);
    
}

void printSquare(Square * square){
    int x;
    printf("[%d][%d] \t", square->row, square->col);    
    printf("Number: %d\t", square->number);
    printf("Solvable: %d\t", square->solveable);
    printf("Possible:[");
    for (x = 0; x<9; x++){
        printf(" %d, ", square->possible[x]);
    }
    printf("]\n");
}