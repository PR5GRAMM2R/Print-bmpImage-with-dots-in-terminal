#include "system.hpp"
#include <ncursesw/curses.h>
// #include <ncurses.h>
#include <unistd.h>
#include <iostream>
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

    // std::cout << 1 << std::endl;/////////////

    ori.loadImage(bmpFileName);

    // std::cout << 2 << std::endl;/////////////

    Screen mainScreen(settedWidth, settedHeight);

    // std::cout << 3 << std::endl;/////////////

    // mainScreen.updateScreen(0, 0, ori.getImage());

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

    char input = 0;
    int widthOffset = 0;
    int heightOffset = 0;

    while(input != 'q'){
        mainScreen.updateScreen(widthOffset, heightOffset, ori.getImage());

        for(int i = 0; i < mainScreen.getHeight(); i++){
            for(int j = 0; j < mainScreen.getWidth(); j++){
                mvwaddwstr(window, i, j, &(mainScreen.getScreenBraille())[i][j]);
            }
            waddch(window, '\n');
        }

        wrefresh(window);

        input = getch();

        switch(input){
            case 'w':
                if(heightOffset == 0)
                    break;
                else
                    heightOffset--;
                break;
            
            case 's':
                if(heightOffset == ori.getHeight() - mainScreen.getHeight())
                    break;
                else
                    heightOffset++;
                break;

            case 'a':
                if(widthOffset == 0)
                    break;
                else
                    widthOffset--;
                break;

            case 'd':
                if(widthOffset == ori.getWidth() - mainScreen.getWidth())
                    break;
                else
                    widthOffset++;
                break;
        }
    }

    endwin();

    return;
}