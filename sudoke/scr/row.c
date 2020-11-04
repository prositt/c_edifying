#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes){
    int i, j, k;

    int sum[9];
    int place[9];

    /* Loop through all rows */
    for(i= 0; i<9; i++){
        
        /* initialize sum to zero */
        for (j = 0; j<9; j++){
            place[j] = 0;
            sum[j] = 0;
        }

        /* loop thorugh each square in row */
        for (j=0; j<9; j++){
            if (sudoku[i][j]->number != 0){
                continue;
            }

            /* loop through all possible */
            for (k=0;k<9;k++){

                /* check if number is possible */
                if(sudoku[i][j]->possible[k] == 0){
                    sum[k]++;
                    place[k] = j;
                }
            }
        }
        for (k = 0; k<9;k++){
            if (sum[k] == 1){
                sudoku[i][place[k]]-> number = k+1;
                sudoku[i][place[k]]-> number = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);
            }
        }
    }

    return 0;
}