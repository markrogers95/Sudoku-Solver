/* Contains the functions concerned with argument
 * validation from the command.
 * 
 * To set flags in the mode structure and verify
 * file input also.
 */

#include<stdio.h>
#include <string.h>

#include "SUDhead.h"

int argValidate (int argc, char *argv[], mode_t *mode ){

    mode->check = 0;
    mode->fileout = 0;
    mode->filein = 0;
    mode->filein = 0;

    int filePosIt = 0;

    printf("Validating arguments and setting mode.\n");
    if (argc < 2){
        printf("No CLIs passed. Returning to main in default mode.\n");
        return 0;
    }
    
    for (int i = 2; i < argc + 1; i++){

        if ( argv[i - 1][0] == '-'){

            for (int j = 1; j < strlen(argv[i-1]); j++){

                if (argv[i-1][j] == 'c'){
                    
                    if (mode->check != 1){
                        mode->check=1;
                    }
                }
                else if (argv[i-1][j] == 'f'){
                    
                    if (mode->fileout != 1){
                        mode->fileout = 1;
                    }
                }
                else{
                    printf("Invalid command line argument: -%c.\n", argv[i-1][j]);
                    return -1;
                }
            }
        }
        else{
            printf("Checking file: %s. ", argv[i-1]);
            if ( fopen(argv[i-1], "r") != NULL){
                printf("File verified.\n", argv[i-1]);
                
                mode->filecount++;
                mode->filepos[filePosIt] = i - 1;
                filePosIt++;

                if (mode->filein != 1){
                    mode->filein = 1;
                }
            }
            else{
                printf("Invalid file, passing control to main for abort.\n");
                return -1;
            }
        }
    }
    if (mode->filein != 1){
        printf("No file detected on command line, passing control to main for abort.\n");
        return -1;
    }
    printf("Finished work.. returning with mode(s): ");
    if (mode->fileout == 1){        
        printf("FILEout ");
    }
    if (mode->check == 1){   
        printf("CHECK\n");
    }
    else printf("DEFAULT\n");

    printf("\n");

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

void printSudFile(int arr[n][n])
{
    FILE * sudFile;
    static int count = 1;

    if (fopen("SUDsolution.txt", "r"))
    {
        sudFile = fopen("SUDsolution.txt", "a");
    }
    else
    {
        sudFile = fopen("SUDsolution.txt", "w");
    }
    
    fprintf(sudFile, "Solution %d:\n", count);
    fprintf(sudFile, "\n");

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            fprintf(sudFile, "%d ", arr[row][col]);
        }
        fprintf(sudFile, "\n");
    }
    fprintf(sudFile, "\n");
    count++;
}