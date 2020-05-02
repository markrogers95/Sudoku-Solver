#include <stdio.h>
#include <stdbool.h>
#include "SUDhead.h"

bool rowCheck(int arr[n][n], int row, int val)
{
    for (int col = 0; col < n; col++)
    {
        if (arr[row][col] == val) return true;
    }
    return false;
}

bool colCheck(int arr[n][n], int col, int val)
{
    for (int row = 0; row < n; row++)
    {
        if (arr[row][col] == val) return true;
    }
    return false;
}

bool boxCheck(int arr[n][n], int boxRowStart, int boxColStart, int val)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (arr[row + boxRowStart][col + boxColStart] == val) return true;
        }
    }
    return false;
}

bool findEmpty(int arr[n][n], int *pRow, int *pCol)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (arr[row][col] == EMPTY)
            {   
                *pRow = row;
                *pCol = col;
                 return true;
            }
        }
    }
    return false;
}

bool validate(int arr[n][n], int row, int col, int val)
{
    return !rowCheck(arr, row, val) &&
           !colCheck(arr, col, val) &&
           !boxCheck(arr, row - row % 3, col - col % 3, val) &&
            arr[row][col] == EMPTY;
}

bool solver(int arr[n][n])
{
    int row, col; 

    if (!findEmpty(arr, &row, &col))
    {
        return true;
    }

    for (int val = 1; val <=9; val++)
    {
        if (validate(arr, row, col, val))
        {
            arr[row][col] = val;
            
            if(solver(arr))
            {
                return true;
            }

            arr[row][col] = EMPTY;
        }
    }
    return false;
}
