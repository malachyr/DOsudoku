
/*
 * Main game logic function. Iterates through each element in the puzzle array, if element == 0 it uses functions checkHor, checkVert and
 * checkGrid to remove numbers from the possible guesses (candidateNums), assigns a random number from the remaining candidateNums and moves
 * to the next element.  If candidate nums is all 0's the attempt is over as there are no valid moves to make and the function returns 0.
 * If the function reaches puzzle[8][8] and this is not equal to 0, the puzzle is solved and gameLogic returns 1.
 */

int gameLogic(int candidateNums[9], int puzzle[9][9]);

/*
 * re-initialises the candidate numbers to contain all numbers from 1-9.
 */

void newNumCandidates(int candidateNums[9]);

/*
 * initialises the 9x9 sudoku board
 */

void initPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]);

/*
 * checks all elements in a horizontal line from the current element, removes any numbers found from candidate numbers
 */

void checkHor(int candidateNums[9], int puzzle[9][9], int row);

/*
 * checks all elements in a vertical line from the current element, removes any numbers found from candidate numbers
 */
void checkVert(int candidateNums[9], int puzzle[9][9], int col);

/*
 * Checks which 3x3 sudoku grid the current element is, iterates through the 3x3 grid and removes any numbers from the
 * candidate numbers
 */

void checkGrid(int candidateNums[9], int puzzle[9][9], int row, int col);

/*
 * Checks that there are any valid candidate numbers, returns 0 if no valid candidate numbers else returns int >0
 */
int checkCandidateNums(int candidateNums[9]);

/*
 * Checks if candidateNums has any valid (int > 0) optins available, if it does asssignRand randomly picks a valid mguess
 * and returns it while also removing the number picked from valid nums.  If no valid numbers available returns 0.
 */

int assignRand(int candidateNums[9]);

/*
 *  Resets puzzle to blank puzzle with user inputs
 */

void resetPuzzle(int puzzle[9][9], int userInitPuzzle[9][9]);