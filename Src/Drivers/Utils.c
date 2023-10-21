#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

void musicPlay()
{

PlaySound(TEXT("music\\music.wav"), NULL, SND_ASYNC);

}
void musicPlay2()
{

PlaySound(TEXT("music\\complete_game.wav"), NULL, SND_SYNC);

}
void musicStop()
{

PlaySound( NULL, 0 , SND_PURGE);

}

void loadingBar(int milliseconds, int totalBars) {

    for (int i = 0; i <= totalBars; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        for (int j = i; j < totalBars; j++) {
            printf(" ");
        }
        printf("] %d%%", i * 100 / totalBars);
        fflush(stdout);
        Sleep(milliseconds);
    }
    printf("\n");

}


void clear_console(){
system("cls");
}

