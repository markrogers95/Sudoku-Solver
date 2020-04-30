# Sudoku-Solver
A Sudoku solver implementing a backtracking algorithm.

Users should be able to pass their sudoku puzzle to the solver ONLY by file as direct input of 99 characters on the command line is too tedious.

The solver itself should run in one of two modes, either a "check" mode or a "solve" mode with the latter being the default behaviour.

If running in "check" mode the user should enter their attempt at solving the sudoku via the command line and on top of their already submitted sudoku file. They should be then be returned a message indicating if they are correct so far or not. 

In the case that the solver shows the user to be incorrect, the user should also be returned their partial solution with in the state is was just prior to the incorrect entry.

If running in "solve" mode the solver should return the correctly completed sudoku to the user.

The output of the solver should be printed either directly to the command line or ouput to a file SUDsolution.txt. The former should be the defualt behaviour.