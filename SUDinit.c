/* Contains functions for setting the sudoku
 * either from input file or from stdin.
 */

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#include "SUDhead.h"

void sudFileRead(int sud[n][n], FILE *readFile){

    char ch;
    int i, j; 
    i = j = 0; 

    ch = fgetc(readFile);

    while (ch != EOF && i < 9){

        if (ch == ' ' || ch == '\n' 
                      || ch == ',' || ch == '{' 
                      || ch == '}'){
            
            ch = fgetc(readFile);
            continue;
        }

        if (j == 9 ){
            j = 0;
            i++;            
        }

        sud[i][j] = atoi(&ch);
        j++;

        ch = fgetc(readFile);
    }
} 

void sudInit(int sud[n][n], mode_t *mode, char *argv[], int argc){

    if (mode->filein == 1){

        printf("File(s) detected on command line. ");
        FILE *sudFile;

        for (int i = 1; i < argc ; i++){

            sudFile = fopen(argv[i], "r");

            if (sudFile){

                sudFileRead(sud, sudFile);
                printf("Successfully read sudoku from %s.\n", argv[i]);
                return;
            }
        }
    }
}