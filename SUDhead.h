#include <stdbool.h>

#define n 9
#define EMPTY 0

typedef struct {
    int check;
    int file;
} mode_t;

void argValidate (int argc, char *argv[], mode_t *mode );
bool solver(int sud[n][n]);
void printSud(int sud[n][n]);