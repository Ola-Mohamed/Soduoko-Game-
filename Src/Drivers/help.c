#include "color.h"

char help_flag=3;
extern matrix[9][9];
extern matrix_solu[9][9];


int help_sudoku (int row , int column)
{
    int flag=-1;

    if(help_flag==0)
    {
        flag =0;
    }
    else
    {
        flag=1;
        matrix[row][column]=matrix_solu[row][column];
        help_flag--;
    }

    return flag;

}
