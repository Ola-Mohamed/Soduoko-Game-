#include "color.h"

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void choosecolor(int color)
{
   switch(color)
   {

    case COLOR_RED:

     setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
   // printf("This is red text\n");
      break;

    case COLOR_GREEN:
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    //printf("This is green text\n");
      break;

    case COLOR_BLUE:
    setColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    //printf("This is green text\n");
      break;

    case COLOR_GRAY :
    setColor(FOREGROUND_INTENSITY| FOREGROUND_INTENSITY);
    break;

    case  COLOR_Yellow :
    setColor(FOREGROUND_RED | FOREGROUND_GREEN);
    break;

    default:
    // Reset the color to default
    setColor(FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_BLUE );
    break;
   }
}
