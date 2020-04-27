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

int main(int argc, char *argv[])
{
    printf("\n");

    mode_t *mode;
    mode = (mode_t *) malloc(sizeof(mode_t));
    assert(mode != NULL);
  
    if (argValidate(argc, argv, mode) != 0){
        printf("Aborting program - invalid argument(s).\n\n");
        return -1;
    }

    int sudoku[n][n];

    sudInit(sudoku, mode, argv, argc);
    printf("\n");

    if (solver(sudoku) == true){

        printf("Solved successfully! ");

        if (mode->fileout == 1){

            printSudFile(sudoku);
            printf("Solution written to file SUDsolution.txt.");
            printf("\n");
        }
        else{
            printf("Solution:\n");
            printf("\n");   
            printSud(sudoku);
        }
    }
    else printf("No solutions found.");
    
    free (mode);
    printf("\n");
    return 0;
}
