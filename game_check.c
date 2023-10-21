#include "color.h"
#define    SIZEe                9

extern matrix[9][9];
extern matrix_solu[9][9];
#define    ARRAY_NAME         matrix


/*************************************************************Choose Game Level******************************************************************/
int choose_level(){

int level=0;
    fflush(stdin);
    choosecolor(COLOR_RED);
    printf("\nEnter level for game");
    choosecolor(COLOR_DEFAULT);
    printf("\nEasy -> 1 Medium -> 2 Hard -> 3 : ");
    while(1){
    scanf("%d",&level);
    switch(level){
        case 1 :
            level =1;
            break;
        case 2 :
            level =2;
            break;
        case 3 :
            level =3;
            break;
        default:
            clear_console();
            return choose_level();
        }
        if(level>0 && level<4){
            break;
        }else{
            /*Do Nothing*/
        }
    }
    return level;
}

/***************************this function to avoid if user repeted num in row or col or in matrix 3*3 **********************************/

int numRepeted(int row, int col,int num)
{

    for(int x=0; x<9; x++)
    {

        //check num is repeated in coloumn
        if(matrix[x][col]==num)
        {
            return 1;
        }

        //check num is repeated in row
        if(matrix[row][x]==num)
        {
            return 2;
        }
    }


    //check num is repeated in square
    int startRow,startCol;
    if((row==0||row==1||row==2)&&(col==0||col==1||col==2))
    {
        startRow = 0;
        startCol = 0;
    }
    else if((row==0||row==1||row==2)&&(col==3||col==4||col==5))
    {
        startRow = 0;
        startCol = 3;

    }
    else if((row==0||row==1||row==2)&&(col==6||col==7||col==8))
    {
        startRow = 0;
        startCol = 6;

    }
    else if((row==3||row==4||row==5)&&(col==0||col==1||col==2))
    {
        startRow = 3;
        startCol = 0;

    }
    else if((row==3||row==4||row==5)&&(col==3||col==4||col==5))
    {
        startRow = 3;
        startCol = 3;

    }
    else if((row==3||row==4||row==5)&&(col==6||col==7||col==8))
    {
        startRow = 3;
        startCol = 6;

    }
    else if((row==6||row==7||row==8)&&(col==0||col==1||col==2))
    {
        startRow = 6;
        startCol = 0;

    }
    else if((row==6||row==7||row==8)&&(col==3||col==4||col==5))
    {
        startRow = 6;
        startCol = 3;

    }
    else if((row==6||row==7||row==8)&&(col==6||col==7||col==8))
    {
        startRow = 6;
        startCol = 6;

    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(matrix[startRow+i][startCol+j]==num)
            {
                return 3;
            }
        }
    }


        /* check if num in wrong place */
    if (matrix_solu[row][col]!= num )
    {
       // flag ++ ;
        return 4 ;
    }

    return 0;

}
