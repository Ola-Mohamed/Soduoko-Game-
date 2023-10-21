#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "color.h"
extern matrix[9][9];
extern help_flag;
void array2d_print(int arr[9][9])//int arr[][5]
{
    //show row step coordinate.
    choosecolor(COLOR_GRAY);
    printf("  0    1    2    3    4    5    6    7    8  ");
    printf("\n\n");
    printf("\n---------------------------------------------\n");

    int j,i;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(arr[i][j]==0)
            {
                printf("    ");
            }
            else
            {
                if(arr[i][j]==matrix[i][j])
                {
                    //printf("\033[1;31m%3d\033[0m ",arr[i][j]);
                    choosecolor(COLOR_BLUE);
                    printf("%3d ",arr[i][j]);
                }
                else
                {
                    choosecolor(COLOR_DEFAULT);
                    printf("%3d ",arr[i][j]);

                }
            }
            choosecolor(COLOR_DEFAULT);
            if((i>=0 && i<=2) && (j>=0 && j<=2)){
            choosecolor(COLOR_Yellow);
            }else if((i>=0 && i<=2) && (j>=5 && j<=8)){
            choosecolor(COLOR_Yellow);
            }else if((i>=3 && i<=5) && (j>=2 && j<=5)){
            choosecolor(COLOR_Yellow);
            }else if((i>=6 && i<=8) && (j>=5 && j<=8)){
            choosecolor(COLOR_Yellow);
            }else if((i>=6 && i<=8) && (j>=0 && j<=2)){
            choosecolor(COLOR_Yellow);
            }
            printf("|");
        }
                //show column step coordinate.
        choosecolor(COLOR_GRAY);
        printf("      %d",i);
        choosecolor(COLOR_DEFAULT);

        printf("\n---------------------------------------------\n");
    }
        choosecolor(COLOR_BLUE);
        printf("\nfor help enter number (10) you have");
        choosecolor(COLOR_GREEN);
        printf(" %d",help_flag);
        choosecolor(COLOR_BLUE);
        printf(" chance.\n");
        choosecolor(COLOR_DEFAULT);

    printf("\n===============================================\n");

}
