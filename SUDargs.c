/* Contains the functions concerned with argument
 * validation from the command.
 * 
 * To set flags in the mode structure and verify
 * file input also.
 */

#include<stdio.h>
#include <string.h>

#include "SUDhead.h"

void flagSet(char arg[], mode_t *mode){

    for (int i = 1; i < strlen(arg); i++){
        
        if (arg[i] == 'c'){
            printf("Triggering check flag!\n");
            mode->check=1;
        }
        else if (arg[i] == 'f'){
            printf("Triggering file output!\n");
            mode->file=1;
        }
        else printf("Not recognized\n");
    }
    printf("%d", mode->file);
    return;
}

void argValidate (int argc, char *argv[], mode_t *mode ){

    for (int i = 1; i < argc + 1; i++)
    {
        if ( argv[i][0] == '-')
        {
            flagSet(argv[i], mode);
        }
        else printf("%s is not a flag!\n", argv[i]);
    }
    return;
}