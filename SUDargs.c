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
    mode->file = 0;

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
                    
                    if (mode->file != 1){
                        mode->file=1;
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
            }
            else{
                printf("Invalid file, passing control to main for abort.\n");
                return -1;
            }
        }
    }
    printf("Finished work.. ");

    if (mode->check == 0 && mode->file == 1){
        
        printf("returning to main in FILEOUT mode.\n");
    }
    else if (mode->file == 0 && mode->check == 1){
        
        printf("returning to main in CHECK mode.\n");
    }
    else if (mode->check == 1 && mode->file ==1){
        
        printf("returning to main in CHECK mode with FILEOUT on.\n");
    }
    else printf("returning to main in DEFAULT mode.\n");

    return 0;
}