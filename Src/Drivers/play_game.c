#include "Utils.h"
#include "color.h"

extern matrix[9][9];
extern matrix_solu[9][9];
extern int choosen_level;


void playGame (){


    musicPlay();
    choosecolor(COLOR_BLUE);
    loadingBar(BAR_SPEED, BAR_SIZE); // Adjust the milliseconds and totalBars as needed
    choosecolor(COLOR_DEFAULT);
    clear_console();
    choosen_level = choose_level();
    clear_console();
    fill_matrix(matrix);
    array2d_print(matrix);
    musicStop();
    take_num_from_user();
}
