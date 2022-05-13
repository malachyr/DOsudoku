#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int gameLogic(int temp[9], int puzzle[9][9]);
void printPuzzle(int puzzle[9][9]);
void newTemp(int temp[9]);
void newPuzzle(int puzzle[9][9]);
void printTemp(int temp[9]);
void checkHor(int temp[9], int puzzle[9][9], int row);
void checkVert(int temp[9], int puzzle[9][9], int col);
void checkGrid(int temp[9], int puzzle[9][9], int row, int col);
int checkTemp(int temp[9]);
int assignRand(int temp[9]);

int numTries = 0;


int main() {

    srand(time(NULL));

    int puzzle[9][9];                                   // game board

    int temp[9];                                        // numbers that can be entered

    int solved = 0;

    int i,j;

    // create game board

    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {
            puzzle[i][j] = 0;
        }
    }


    newPuzzle(puzzle);

    printf("start board:\n");
    printPuzzle(puzzle);


    // create temp

    for (i = 0; i < 9; i++) {

        temp[i] = i + 1;

    }

    while (solved != 1) {

        newPuzzle(puzzle);
        solved = gameLogic(temp, puzzle);
        numTries += 1;
       // printf("numTries: %i", numTries);


    }

    printf("solved!\n");
    printf("numTries: %i\n", numTries);
    printPuzzle(puzzle);


    return 0;

} // end main

int gameLogic(int temp[9], int puzzle[9][9]) {

    int i, j;
    int checkStuck;

    for (i = 0; i < 9; i++) {

        for (j = 0; j < 9; j++) {

            if (puzzle[i][j] == 0) {
                // is zero
                newTemp(temp);
                checkHor(temp, puzzle, i);
                checkVert(temp, puzzle, j);
                checkGrid(temp,puzzle,i,j);
               // printTemp(temp);
              //  printPuzzle(puzzle);
                checkStuck = assignRand(temp);                     // returns 0 for no candidate numbers (stuck) or a value bet ween 1 - 9

                if (checkStuck != 0) {

                    puzzle[i][j] = checkStuck;

                }

                if (checkStuck == 0) {
                    //printPuzzle(puzzle);
                    return 0;

                }


            }

        }

        if (i >= 8 && j >= 8 && puzzle[8][8] != 0) {

            printf("SOLVED!!!!!!!!!!\n");
            return 1;

        }

    }

} // end game logic



void newPuzzle(int puzzle[9][9]) {

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

void newTemp(int temp[9]) {

    int i;

    for (i = 0; i < 9; i++) {

        temp[i] = i + 1;

    }

} // end newTemp

void printTemp(int temp[9]) {

    int i;

    printf("temp: ");

    for (i=0;i<9;i++){

        printf("%i ", temp[i]);

    }

    printf("\n\n");

} // end of printTemp

void checkHor(int temp[9], int puzzle[9][9], int row) {

    int i;

    for (i=0;i<9;i++) {

        if (puzzle[row][i] != 0) {

            temp[ (puzzle[row][i] - 1 ) ] = 0;

        }

    }

} // end of checkHor

void checkVert(int temp[9], int puzzle[9][9], int col){

    int i;

    for (i=0;i<9;i++) {

        if (puzzle[i][col] != 0) {

            temp[ (puzzle[i][col] - 1 ) ] = 0;

        }

    }

} // end checkVert

void checkGrid(int temp[9], int puzzle[9][9], int row, int col) {
    //printf("checkGrid ran row: %i col %i\n", row, col);
    int gridSwitch;

    int i,j;

    if (row < 3 && col < 3) { gridSwitch = 1;}
    if (row < 3 && col > 2 && col < 6) { gridSwitch = 2;}
    if (row < 3 && col > 5 ) { gridSwitch = 3;}
    if (row > 2 && row < 6 && col < 3) { gridSwitch = 4;}
    if (row > 2 && row < 6 && col > 2 && col < 6) { gridSwitch = 5;}
    if (row > 2 && row < 6 && col > 5) { gridSwitch = 6;}
    if (row > 5 && col < 3) { gridSwitch = 7;}
    if (row > 5 && col > 2 && col < 6) { gridSwitch = 8;}
    if (row > 5 && col > 5) { gridSwitch = 9;}

    //printf("gridSwitch: %i\n", gridSwitch);

    switch (gridSwitch) {

        case 1:
            for (i=0;i<3;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
           // printf("case 1 temp: ");
          //  printTemp(temp);
            break;
        case 2:
            for (i=0;i<3;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 3:
            for (i=0;i<3;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 4:
            for (i=3;i<6;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 5:
            for (i=3;i<6;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 6:
            for (i=3;i<6;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 7:
            for (i=6;i<9;i++){
                for (j=0;j<3;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 8:
            for (i=6;i<9;i++){
                for (j=3;j<6;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
        case 9:
            for (i=6;i<9;i++){
                for (j=6;j<9;j++) {
                    if(puzzle[i][j]!=0){
                        temp[ (puzzle[i][j] - 1 ) ] = 0;
                    }
                }
            }
            break;
    } // end switch

} // end checkGrid

int checkTemp(int temp[9]) {

    int i;
    int sum = 0;

    for (i=0;i<9;i++) {

        sum += temp[i];

    }

    return sum;
}

int assignRand(int temp[9]) {

   // printf("assign rand ");
   // printTemp(temp);

    int number;
    int found = 0;
    int a;
    int isStuck = 1;

    isStuck = checkTemp(temp);

    if (isStuck == 0) {

      //  printf("is stuck!\n");
        return 0;
    }



    while (found == 0) {

        a = rand() % 9;

        if (temp[a] != 0) {

            number = temp[a];
            temp[a] = 0;

            found = 1;

        }

    }



    //printf("rand: %i number: %i\n", a,number);

    return number;

}


