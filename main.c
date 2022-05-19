#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "io.h"
#include "gameLogic.h"



int numTries = 0;


int main() {

    srand(time(NULL));

    int puzzle[9][9];                                               // create game board

    int userInitPuzzle[9][9] = {0};                                 // create puzzle board for user inputted numbers, set to all zeros

    int candidateNums[9];                                           // create array of candidate numbers

    int solved = 0;

    initPuzzle(puzzle, userInitPuzzle);

    printf("start board:\n");
    printPuzzle(puzzle);

    newNumCandidates(candidateNums);  // initialise candidate numbers array

    while (solved != 1) {

        resetPuzzle(puzzle,userInitPuzzle);
        solved = gameLogic(candidateNums, puzzle);
        numTries += 1;

    }

    printf("numTries: %i\n", numTries);
    printPuzzle(puzzle);

    return 0;

} // end main




