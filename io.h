

/*
 *  Prints the game board at its current state to stdout
 */

void printPuzzle(int puzzle[9][9]);


/*
 * Takes in user input for an already existing puzzles, user inputs element and value through 3 ints. Horizontal position
 * vertical position and value. When resetting after a failed attempt, this userInitPuzzle is called as the starting point
 * for each attempt.
 */

void initPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]);