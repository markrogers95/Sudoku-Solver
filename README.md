# Sudoku-Solver
A Sudoku solver implementing a backtracking algorithm.

Users should be able to pass their sudoku to the solver either by file or direct command line input. This should be governed by arguemnts when starting the solver.

The solver should run in one of two modes, either a "check" mode or a "solve" mode.

If running in "check" mode the user should enter their attempt at solving the sudoku and be returned a message indicating if they are correct so far, or not. In the case that the solver shows the user to be incorrect, the user should also be returned the first wrong entry (in row-column order).

If running in "solve" mode the solver should return the correctly completed sudoku to the user, either on the command line or written to file, dependent on input method.
