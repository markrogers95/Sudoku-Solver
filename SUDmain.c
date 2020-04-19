/* Currently input must be hard coded and
 * compiled against. Not ideal and will change
 * this soon.
 * 
 * Main will eventually assess command line
 * arguments and read/write either from/to
 * stdin/stdout or file.
 * 
 * Currently the print functions sits here 
 * but will most likely be moved when more 
 * utility functions are added.
 */

#include <stdio.h>
#include <stdbool.h>

#include "SUDhead.h"

void printSud(int arr[n][n]);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("\nNo arguments supplied. Program will run in solve ");
        printf("mode and output to screen, subject to user input.\n");
        printf("Do you wish to continue? ");
        printf ("[1] Continue.");
        printf ("[2] Exit. ");

        int cli = 0;

        while(cli != 1)
        {
            scanf ("%d", &cli);

            if (cli == 2)
            {
                printf(".. exiting.\n");
                return 0;
            }
            else if (cli == 1)
            {
                printf(".. continuing.\n");
                cli = 1;
            }
            else
            {
                printf("You must press 1 or 2.\n");
            }
        }
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