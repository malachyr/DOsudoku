#include <stdio.h>
#include <string.h>

#include "io.h"

void printPuzzle(int puzzle[9][9]) {

    int i,j;

    for (i=0;i<9;i++) {

        for (j=0;j<9;j++) {

            printf("%i ", puzzle[i][j]);
        }

        printf("\n");

    }
    printf("\n");

} // end printPuzzle

void initPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]) {

    int x = 10;
    int y =10;
    int value = 10;

    printf("please enter row, column and number with a space between each entry.\nFirst number is the row number starting at 0 and finishing at 8\n");
    printf("Second number is the column number starting at 0 and finishing at 8\nLast number is the value of the element from 1 - 9\n");
    printf("e.g. top left of the Sudoku board with value 8, enter '0 0 8'\n");
    printf("  0 1 2 3 4 5 6 7 8\n0 8 * * * * * * * * \n1 * * * * * * * * *\n2 * * * * * * * * *\n");

    while ( (x > 0) || (value > 0) || (y > 0) ) {



        scanf(" %i %i %i", &x,&y,&value);
        if ( x > 8 || y > 8 || value > 9) { printf("Please enter numbers below 8 for row or column and below 9 for the value\n"); }
        else if ( x < 0 || y < 0 || value < 1) { printf("Please enter numbers above -1 for row or column and above 0 for the value\n"); }
        else {
            userInitPuzzle[x][y] = value;
            printf("Entered!\n");
        }

    }

    memcpy(puzzle, userInitPuzzle, 324);

}