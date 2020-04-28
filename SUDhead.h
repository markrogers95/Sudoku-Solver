#include <stdbool.h>

#define n 9
#define EMPTY 0

typedef struct {
    int check;
    int fileout;
    int filein;

    int filecount;
    int filepos[5];

} mode_t;

int argValidate (int argc, char *argv[], mode_t *mode );
void sudInit(int sud[n][n], char *argv);
bool solver(int sud[n][n]);
void printSud(int sud[n][n]);
void printSudFile(int sud[n][n]);