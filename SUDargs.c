/* Contains the functions concerned with argument
 * validation from the command.
 * 
 * To set flags in the mode structure and verify
 * file input also.
 */

#include<stdio.h>
#include <string.h>

#include "SUDhead.h"

void argValidate (int argc, char *argv[], mode_t *mode ){

    printf("Checking arguments.. ");
    if (argc < 2){
        printf("no CLIs passed. Returning to main in default mode.\n");
        return;
    }
    printf("\n");
    for (int i = 2; i < argc + 1; i++){

        if ( argv[i - 1][0] == '-'){

            for (int j = 1; j < strlen(argv[i-1]); j++){

                if (argv[i-1][j] == 'c'){
                    
                    if (mode->check != 1){
                        printf("Check flag acknowledged..\n");
                        mode->check=1;
                    }
                }
                else if (argv[i-1][j] == 'f'){
                    
                    if (mode->file != 1){
                        
                        printf("File output acknowledged..\n");
                        mode->file=1;
                    }
                }
                else{
                    printf("\n-%c is not a valid command line", argv[i-1][j]);
                    printf(" argument. It will be ignored.\n");
                }
            }
        }
        else printf("%s is a FILE to be verified.\n", argv[i-1]);
    }
    printf("Finished validating arguments..");

    if (mode->check == 0 && mode->file == 1){
        
        printf("returning to main in FILEOUT mode.\n");
    }
    else if (mode->file == 0 && mode->check == 1){
        
        printf("returning to main in CHECK mode.\n");
    }
    else if (mode->check == 1 && mode->file ==1){
        
        printf("returning to main in CHECK mode with FILEOUT on.\n");
    }
    else printf("returning to main in DEFAULT mode.");

    return;
}