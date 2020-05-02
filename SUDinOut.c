#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SUDhead.h"

static void printHelp();

int argValidate (int argc, char *argv[], mode_t *mode ){

    mode->check = 0;
    mode->fileout = 0;
    mode->filein = 0;
    mode->filein = 0;

    int filePosIt = 0;

    printf("Validating arguments and setting mode.\n");
    if (argc < 2){
        printHelp();
        return 1;
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

void printSud(int arr[n][n], mode_t *mode)
{
    static int count = 1;

    if (mode->check ==1){
        printf("\nPartial solution %d:\n", count);
    }
    else printf("Solution %d:\n", count);

    printf("\n");

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", arr[row][col]);
        }
        printf ("\n");
    }

    count++;
}

void printSudFile(int arr[n][n], mode_t *mode)
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
    
    if (mode->check == 1){
        fprintf(sudFile, "Not bad, partial solution %d, try again from here:\n", count);
        fprintf(sudFile, "\n");

    }
    else{
        fprintf(sudFile, "Solution %d:\n", count);
        fprintf(sudFile, "\n");
    }

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

void checkMode(int sud[n][n], int sudcpy[n][n]){

    printf("\nFollow the instructions to check your efforts.\n");
    printf("Enter the row number, followed by the column number, "
           "followed by the value you wish to insert."
           "\nPlease remember that array indexing starts at zero!\n");

    int i, j;
    while (sud != sudcpy){
              
        int v;

        printf("\nEnter row: ");
        scanf("%d", &i);

        printf("Enter column: ");
        scanf("%d", &j);

        printf("Enter value: ");
        scanf("%d", &v);
        sudcpy[i][j] = v;

        if (sud[i][j] != sudcpy[i][j]){

            printf("\nNot quite!");
            sudcpy[i][j] = 0;
            return;
        }

    }
    return;
}

void printHelp(){

    printf("\nSudoku-Solver help:");
    printf("\n");
    printf("\nFirst start by entering your Sudoku in a regular text file - "
           "notepad as an editor would suffice.\nYou can enter your Sudoku enclosed "
           "between '{}' or '()' braces, spread over 9 lines, delimited with spaces "
           "\nand/or commas as you wish, but no other characters should be entered. "
           "Where the puzzle shows a blank square \nplease enter 0. You can then pass the name of " 
           "this file as an argument on the command line for solving, \nsupplying the "
           "relevent path if it is not located in the same directory.");
    printf("\n");
    printf("\nBy default the solver will solve the Sudoku and print the output to screen. "
           "If you wish for different behaviour, \nyou must specify on the command line. "
           "Enter '-f' to set output to file and use '-c' to enter check mode. \nAny arguments "
           "not preceeded by a hyphon will be interpreted as files for validating.");
    printf("\n");
    printf("\nIf in check mode the solver will ask you to enter your attempted solution "
           "and only stop you when you are wrong \nor have solved the puzzle. In "
           "the case you are wrong the solver will return to you a partial solution with "
           "your \ncorrect guesses so far.");
    printf("\n");
    printf("\nAs mentioned, by default the output will be printed to screen but if you "
           "choose to have the output written to file \nyou will find this in a regular "
           "text file, SUDsolution.txt, in the directory you are running from.");
    printf("\n");
    printf("\nEnjoy!\n");
    printf("\n");
}