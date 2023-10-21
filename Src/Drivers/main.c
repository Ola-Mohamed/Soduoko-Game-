#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "color.h"


int matrix[9][9]={0};
int matrix_solu[9][9]={0};
int choosen_level=0;


#define    ARRAY_NAME       matrix



int main()
{

    playGame ();

    return 0;
}


//return 1 completed
int check_complete()
{
    char *p=*matrix;
    for(int x=0; x<81; x++)
    {
        if(*(*matrix+x)==0)
        {
            return 0;
        }
    }
    return 1;
}


void take_num_from_user()
{
    if(check_complete())
    {
        choosecolor(COLOR_GREEN);
        printf("\nCongratulations You finish the game \n");
        choosecolor(COLOR_DEFAULT);
        musicPlay2();
        return 1;
    }else{
        /*Do nothing*/
    }
    printf("\nEnter number from 1 to 9 : ");
    int num;
    //pointer to get first char in int to ignore problem of scanf char
    char *pNum=&num;
    scanf("%d",&num);
    fflush(stdin);
    if((*pNum<10) && (*pNum>0))
    {
        //printf("%c",num+'0');
        return take_coordinate_from_user(num);
    }
    else if (*pNum==10){
        return take_coordinate_from_user(num);
    }else
    {
        clear_console();
        array2d_print(matrix);
        return take_num_from_user();
    }
}

void take_coordinate_from_user(char num)
{
    int row=-1,col=-1;
    char *pRow = &row;
    char *pCol = &col;
    printf("Enter row from 0 to 8 : ");
    while(1)
    {
        fflush(stdin);
        scanf("%d",&row);
        if(*pRow>=0 && *pRow<9)
        {
            break;
        }
        clear_console();
        array2d_print(matrix);
        printf("\nEnter number from 1 to 9 : %c",num+'0');
        printf("\nEnter row from 0 to 8 : ");

    }
    printf("Enter column from 0 to 8 : ");
    while(1)
    {
        fflush(stdin);
        scanf("%d",&col);
        if(*pCol>=0 && *pCol<9)
        {
            break;
        }
        clear_console();
        array2d_print(matrix);
        printf("\nEnter number from 1 to 9 : %c",num+'0');
        printf("\nEnter row from 0 to 8 : %c",*pRow+'0');
        printf("\nEnter column from 0 to 8 : ");

    }
    return set_num(num,*pRow,*pCol);
}

void set_num(char num,int row,int col)
{
    // return 1 if override on random
    if(check_override_on_random(row,col))
    {
        return take_num_from_user();
    }else if (num==10){

        if(help_sudoku(row,col)){
        clear_console();
        array2d_print(matrix);

        }else{
        clear_console();
        array2d_print(matrix);
        }

    }
    //check num repeated in row and coloumn
    //return 1 if repeated
    else if(numRepeted(row,col,num)==1 ||numRepeted(row,col,num)==2||numRepeted(row,col,num)==3 ||numRepeted(row,col,num)==4 )
    {
        int type_error=numRepeted(row,col,num);
        choosecolor(COLOR_RED);
        matrix[row][col]=num;
        clear_console();
        array2d_print(matrix);
        choosecolor(COLOR_RED);
        switch(type_error){
        case 1 :
        printf("cant repeated this num in the same column");
            break;
        case 2 :
        printf("cant repeated this num in the same row");

            break;
        case 3 :
        printf("cant repeated this num in the same square");
            break;
        case 4 :
        printf("The num in the WRONG place");
            break;

        }
       // printf("cant repeated this num in the same row,column and square");
        choosecolor(COLOR_DEFAULT);
        matrix[row][col]=0;

    }
    else
    {
        clear_console();
        matrix[row][col]=num;
        array2d_print(matrix);
    }
    return take_num_from_user();
}

int check_override_on_random(int row,int col)
{
    //check if user override on random nums start play
    if(matrix[row][col]!=0)
    {
        clear_console();
        array2d_print(matrix);
        choosecolor(COLOR_RED);
        printf("This place cant override");
        choosecolor(COLOR_DEFAULT);
        return 1;
    }
    return 0;
}
