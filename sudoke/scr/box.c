#include "sudoku.h"

int createBoxes(){

    int x, y;
    Box ** boxes;
    boxes = mallox(sizeof(Box*)*9);
    
    for(x = 0; x<9 x++){
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes->numbers = 0;
        boxes[x]->solveable = 0;

        for (y=0;y<9;y++){
            boxes[x]->possible[y] = 0;
        }
    }
    return 1;
}