#include "system.hpp"
#include <ncursesw/curses.h>
// #include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
// #include <locale>
// #include <codecvt>

System::System(const char * bmpFileName, int settedWidth, int settedHeight)
    : bmpFileName( (char *)bmpFileName ), settedWidth( settedWidth ), settedHeight( settedHeight )
{
    
}
        
System::~System()
{
    bmpFileName = NULL;
    settedWidth = 0;
    settedHeight = 0;
}

void System::startSystem()
{
    Original ori;

    ori.loadImage(bmpFileName);

    Screen mainScreen(settedWidth, settedHeight);

    mainScreen.updateScreen(0, 0, ori.getImage());

    WINDOW * window;

    initscr();

    if(has_colors == FALSE){
        puts("Terminal does not support colors!");
        endwin();
        return;
    }
    else{
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }

    refresh();

    window = newwin(mainScreen.getHeight() / 4, mainScreen.getWidth() / 2, 0, 0);

    wbkgd(window, COLOR_PAIR(1));

    for(int i = 0; i < mainScreen.getHeight(); i++){
        for(int j = 0; j < mainScreen.getWidth(); j++){
            mvwaddwstr(window, i, j, &(mainScreen.getScreenBraille())[i][j]);
        }
        waddch(window, '\n');
    }
   
    wrefresh(window);

    getch();

    endwin();

    return;
}