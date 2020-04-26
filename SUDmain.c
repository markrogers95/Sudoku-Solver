/* Main processes command line arguments to determine mode.
 * 
 * Sudoku will be initiliased and either input from stdin
 * or by a read from file - currently functionality only
 * extends to one file.
 * 
 * Sudoku is then solved and sent to screen, or back to file.  
 */

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "SUDhead.h"

void printSud(int arr[n][n]);

int main(int argc, char *argv[])
{

    mode_t *mode;
    mode = (mode_t *) malloc(sizeof(mode_t));
    assert(mode != NULL);

    if (argValidate(argc, argv, mode) != 0){
        printf("Aborting program - invalid argument(s).");
        return -1;
    }

    int sudoku[n][n];

    sudInit(sudoku, mode, argv, argc);

    if (solver(sudoku) == true){

        printf("Solved successfully! Solution:\n");   
        printSud(sudoku);
    }
    else printf("No solutions found.");
    
    free (mode);
    return 0;
}

void printSud(int arr[n][n])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", arr[row][col]);
        }
        printf ("\n");
    }
}
