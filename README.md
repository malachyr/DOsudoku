# DOsudoku
#
# 

A brute force sudoku solver written in C with base libraries.

The code starts by creating a 9 x 9 array and filling it with zeros, zeros are used to represent blank squares in the puzzle.  

There is also an array (temp) representing the possible numbers (1-9) that can be placed in any element.

Squares that are already known are added by specific element definitions in the newPuzzle function.

Each array element is then evaluated left to right ([0][0] - [0][8]) and row by row.  At each element 5 checks are made:

isZero - If the element is not zero, then the current value has been manually assigned as one of the clue numbers in the puzzle
and the code moves to the next element.  If the element is 0 then a possible move can be made and the below checks are made.

checkHor - iterates through the entire row, any element that != 0 is removed from the potential pool of numbers (temo)

checkVert - iterates through the entire coloumn, any element that != 0 is removed from the potential pool of numbers (temo)

checkGrid - a sudoku board is divided up into 9 squares of 3 x 3 numbers, this checks where the current element is in the puzzle
and iterates through the relvant square removing any numbers from the pool (temp)

checkStuck - checks that temp is not all 0's, if it is, this means a mistake has been made somewhere in the previously entered numbers and
the program starts again from the begining.

If checkStuck is not all 0's, then there is a possible valid move to make.  The code randomly selects one of the potential numbers from temp,
assigns it to the current array element and moves to the next element, where it performs all the checks above again.

This coninues until the code has reached the last element (puzzle[8][8]) and that element !=0, at which point the program belives the puzzle
is solved and outputs the solution.


This code is wildly ineffecient, it is pure brute force.  It makes no effort to learn if it is getting any result consistantly, e.g. this row
of guesses allows it to continue x% of the time so it should favour this as probably being correct, nor does it try to start with the rows,
coloums or squares with the most amount of pre filled numbers which would give it a better probablillity of success in guessing the remaining
empty squares correctly.

The code also can not tell if a puzzle is valid (has a solution), in which case it will guess forever, or that a puzzle has only one solution.

If there are multiple solutions it will display the first valid solution it finds.

Using puzzles rated as 'hard' from sudoku-solutions.com the code gets the correct answer, on average, in 2.12 seconds with 1,359,893 guesses.

min: 0.53 seconds 400064 guesses max: 4.26 seconds 2987186 guesses
