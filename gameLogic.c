#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gameLogic.h"
#include "io.h"



int gameLogic(int candidateNums[9], int puzzle[9][9]) {

    int i, j;
    int checkStuck;

    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {

            if (puzzle[i][j] == 0) {

                newNumCandidates(candidateNums);
                checkHor(candidateNums, puzzle, i);
                checkVert(candidateNums, puzzle, j);
                checkGrid(candidateNums, puzzle, i, j);
                checkStuck = assignRand(candidateNums);                     // returns 0 for no candidate numbers (stuck) or a value bet ween 1 - 9

                if (checkStuck != 0) {

                    puzzle[i][j] = checkStuck;                              // if checkStuck returns a number != 0 the number returned is a valid guess
                                                                            // for the element puzzle[i][j]
                }

                if (checkStuck == 0) {                                      // if checkStuck returns 0, there are no valid guesses for this element
                                                                            // the attempt is over returns 0 and restarts from puzzle[0][0]
                    return 0;

                }

            }

        }

        if (i >= 8 && j >= 8 && puzzle[8][8] != 0) {

            printf("SOLVED!\n");
            return 1;

        }

    }

} // end game logic


/*

void initPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]) {

    int i,j;

    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {
            puzzle[i][j] = 0;
        }
    }

    // enter known numbers

    puzzle[0][4] = 8;
    puzzle[0][5] = 7;
    puzzle[0][6] = 2;
    puzzle[1][1] = 1;
    puzzle[1][3] = 6;
    puzzle[1][6] = 4;
    puzzle[1][8] = 9;
    puzzle[2][1] = 5;
    puzzle[2][7] = 8;
    puzzle[3][4] = 4;
    puzzle[3][7] = 9;
    puzzle[3][8] = 7;
    puzzle[4][2] = 9;
    puzzle[4][6] = 3;
    puzzle[5][0] = 4;
    puzzle[5][1] = 3;
    puzzle[5][4] = 7;
    puzzle[6][1] = 8;
    puzzle[6][7] = 1;
    puzzle[7][0] = 9;
    puzzle[7][2] = 2;
    puzzle[7][5] = 8;
    puzzle[7][7] = 4;
    puzzle[8][0] = 1;
    puzzle[8][2] = 6;
    puzzle[8][3] = 9;
    puzzle[8][4] = 5;




}
*/


void newNumCandidates(int candidateNums[9]) {

    int i;

    for (i = 0; i < 9; i++) {

        candidateNums[i] = i + 1;

    }

} // end newNumCandidates

void checkHor(int candidateNums[9], int puzzle[9][9], int row) {

    int i;

    for (i=0;i<9;i++) {

        if (puzzle[row][i] != 0) {

            candidateNums[ (puzzle[row][i] - 1 ) ] = 0;

        }

    }

} // end of checkHor

void checkVert(int candidateNums[9], int puzzle[9][9], int col){

    int i;

    for (i=0;i<9;i++) {

        if (puzzle[i][col] != 0) {

            candidateNums[ (puzzle[i][col] - 1 ) ] = 0;

        }

    }

} // end checkVert

void checkGrid(int candidateNums[9], int puzzle[9][9], int row, int col) {

    int gridSwitch;

    int i,j;

    // find which 3x3 grid the current

    if (row < 3 && col < 3) { gridSwitch = 1;}
    if (row < 3 && col > 2 && col < 6) { gridSwitch = 2;}
    if (row < 3 && col > 5 ) { gridSwitch = 3;}
    if (row > 2 && row < 6 && col < 3) { gridSwitch = 4;}
    if (row > 2 && row < 6 && col > 2 && col < 6) { gridSwitch = 5;}
    if (row > 2 && row < 6 && col > 5) { gridSwitch = 6;}
    if (row > 5 && col < 3) { gridSwitch = 7;}
    if (row > 5 && col > 2 && col < 6) { gridSwitch = 8;}
    if (row > 5 && col > 5) { gridSwitch = 9;}


    switch (gridSwitch) {

        case 1:
            for (i=0;i<3;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 2:
            for (i=0;i<3;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 3:
            for (i=0;i<3;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 4:
            for (i=3;i<6;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 5:
            for (i=3;i<6;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 6:
            for (i=3;i<6;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 7:
            for (i=6;i<9;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 8:
            for (i=6;i<9;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 9:
            for (i=6;i<9;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        candidateNums[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        default: {
            printf("missed grid assignment!\n");
        }
    } // end switch

} // end checkGrid

int checkCandidateNums(int candidateNums[9]) {

    int i;
    int sum = 0;

    for (i=0;i<9;i++) {

        sum += candidateNums[i];

    }

    return sum;
}

int assignRand(int candidateNums[9]) {

    int number;
    int found = 0;
    int a;
    int isStuck = 1;

    isStuck = checkCandidateNums(candidateNums);  // if 0 is returned, candidateNums is all 0's so there are no valid guesses to be made and attempt needs to restart

    if (isStuck == 0) {

        return 0;

    }

    while (found == 0) {

        a = rand() % 9;                                                 // pick a random number between 0 - 8

        if (candidateNums[a] != 0) {                                    // use that to check a random element in the array != 0

            number = candidateNums[a];
            candidateNums[a] = 0;

            found = 1;

        }

    }

    return number;

}

void resetPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]) {

    memcpy(puzzle,userInitPuzzle, 324);

        }