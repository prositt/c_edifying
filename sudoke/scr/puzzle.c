#include "sudoku.h"


Square *** setUpPuzzle(int ** puzzle){
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();
    /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; i++){

        /* malloc space for each row */
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
        
        /* loop through columns*/
        for (j = 0; j < SIZE_COLS; j++){

            /* malloc space for each square */
            sudoku[i][j] = (Square*)malloc(sizeof(Square*)*9);
            
            /* assign number to sudoku adt */
            sudoku[i][j] -> number = puzzle[i][j];

            /* assign row and col numbers to each square */
            sudoku[i][j]->row = i;
            sudoku[i][j]->col = j;
            sudoku[i][j]->solveable = 9;

            /*boxes...*/
            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (x=0; x < SIZE_ROWS; x++){
                sudoku[i][j]->possible[x] = 0;
            }
        }
    }

    /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; i++){
      
        /* loop through columns*/
        for (j = 0; j < SIZE_COLS; j++){

            if(sudoku[i][j]->number != 0){
            sudoku[i][j]->solveable = 0;
            updateSudoku(sudoku, i, j);
            UNSOLVED--;
            }
        }

    }
    return sudoku;
}

int updateSudoku(Square *** sudoku, int row, int col){
    int x;
    int number = sudoku[row][col]->number;

    /* loops through columns */
    for (x = 0; x < SIZE_ROWS; x++){
        if (sudoku[x][col]->possible[number-1] == 0){
            sudoku[x][col]->solveable--;
        }
        sudoku[x][col]->possible[number-1] == 1;
    }
    /* loops through columns */
    for (x = 0; x < SIZE_COLS; x++){
        if (sudoku[row][col]->possible[number-1] == 0){
            sudoku[row][x]-> solveable--;
        }
        sudoku[x][row]->possible[number-1] == 1;
    }
    return 1;
}

int checkPuzzle(Square *** sudoku){
    int i, j, x;

        /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; i++){
      
        /* loop through columns*/
        for (j = 0; j < SIZE_COLS; j++){
            if(sudoku[i][j]->solveable == 1){
                printf("Solved: %d, %d\n", i, j);  
                solveSquare(sudoku[i][j]);
                updateSudSolvedoku(sudoku, i, j);
            }
        }
    }
}

int ** createPuzzle(){
    int ** puzzle;
    int i, j;
    int array[9][9] = { 0, 1, 9,    0, 0, 2,    0, 0, 0,
                        4, 7, 0,    6, 9, 0,    0, 0, 1,
                        0, 0, 0,    4, 0, 0,    0, 9, 0,
                        
                        8, 9, 4,    5, 0, 7,    0, 0, 0,
                        0, 0, 0,    0, 0, 0,    0, 0, 0,
                        0, 0, 0,    2, 0, 1,    9, 5, 8,
                        
                        0, 5, 0,    0, 0, 6,    0, 0, 0,
                        6, 0, 0,    0, 2, 8,    0, 7, 9,
                        0, 0, 0,    1, 0, 0,    8, 6, 0 };
    
    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < SIZE_ROWS; i++){
        puzzle[i] = (int*)malloc(sizeof(int*)*9);

        for (j = 0; j < SIZE_COLS; j++){
            puzzle[i][j] = array[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(Square *** puzzle){
    int i, j;

    printf("------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++){
        /* Print each row */
        for (j = 0; j < SIZE_COLS; j++){
            printf(" %d ", puzzle[i][j]->number);

            if((j+1) % 3 == 0){
            printf("|");
            }
        }
        printf("\n");
        if((i+1) % 3 == 0){
            printf("---------+---------+----------\n");
        }
    }
}