/* Currently input must be hard coded and compiled against. 
 * This is not ideal and will be changed next.
 * 
 * Main processes command line arguments to determine mode.
 * 
 * Sudoku will be initiliased and either directly input by
 * or read from file.
 * 
 * Sudoku is then solved and sent to screen, or back to file. 
 * 
 */

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "SUDhead.h"

void printSud(int arr[n][n]);

int main(int argc, char *argv[])
{

    //initialise mode structure
    mode_t *mode;
    mode = (mode_t *) malloc(sizeof(mode_t));
    assert(mode != NULL);

    //validate arguments, process flags and verify files
    if (argValidate(argc, argv, mode) != 0){
        printf("Aborting program - invalid argument(s).");
        return -1;
    }

    int sud[n][n] = {{0,0,0,8,2,0,0,6,0},
                     {0,9,1,0,0,0,0,4,0},
                     {5,0,0,0,1,0,0,0,2},
                     {0,0,0,5,0,0,0,2,8},
                     {0,0,7,0,0,0,6,0,0},
                     {9,5,0,0,0,1,0,0,0},
                     {3,0,0,0,7,0,0,0,6},
                     {0,7,0,0,0,0,4,1,0},
                     {0,4,0,0,6,5,0,0,0}};

    if (solver(sud) == true) printSud(sud);
    else printf("Nope, impossible.");

    free (mode);
    return 0;
}

void printSud(int arr[n][n])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d %s", arr[row][col], " ");
        }
        printf ("\n");
    }
}