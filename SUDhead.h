#include <stdbool.h>

#define n 9
#define EMPTY 0

typedef struct {
    int check;
    int fileout;
    int filein;
} mode_t;

int argValidate (int argc, char *argv[], mode_t *mode );
void sudInit(int sud[n][n], mode_t *mode, char *argv[], int argc);
bool solver(int sud[n][n]);
void printSud(int sud[n][n]);
void printSudFile(int sud[n][n]);