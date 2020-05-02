#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "SUDhead.h"

int main(int argc, char *argv[])
{
    printf("\n");

    mode_t *mode;
    mode = (mode_t *) malloc(sizeof(mode_t));
    assert(mode != NULL);
  
    int i = argValidate(argc, argv, mode);

    if (i != 0){

        if (i == -1){
            printf("Aborting program - invalid argument(s).\n\n");
            return -1;
        }
        else return -1;
    }

    printf("Found %d file(s) to process.\n", mode->filecount);

    int sudoku[n][n], sudcopy[n][n];

    for (int i = 0; i < sizeof(mode->filepos)/sizeof(int); i++){

        if (mode->filepos[i]){

            sudInit(sudoku, argv[mode->filepos[i]]);

            if (mode->check == 1){
                memcpy(sudcopy, sudoku, sizeof(sudoku));
            }

            if (solver(sudoku) == true){

                printf("\nThis puzzle is solveable!\n");

                if (mode->check == 1){

                    printf("\nWe are in check mode!\n");
                    checkMode(sudoku, sudcopy); 

                    if (mode->fileout == 1){

                        printSudFile(sudcopy, mode);
                        printf("\nPartial solution written to file SUDsolution.txt.\n");
                        printf("\n");
                    }
                    else{
                        printf("\n");   
                        printSud(sudcopy, mode);
                        printf("\n");
                    }                   
                    
                }
                else if (mode->check == 0){

                    if (mode->fileout == 1){

                        printSudFile(sudoku, mode);
                        printf("\nSolution written to file SUDsolution.txt.\n");
                        printf("\n");
                    }
                    else{
                        printf("\n");   
                        printSud(sudoku, mode);
                        printf("\n");
                    }
                }
            }
            else printf("\nThere are no solutions to this puzzle!\n");
        }
    }
    
    free (mode);
    printf("\n");
    return 0;
}
