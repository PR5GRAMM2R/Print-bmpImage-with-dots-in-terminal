#include "screen.hpp"

// Screen::Screen()
// {

// }

Screen::Screen(int inputWidth, int inputHeight)
    : width( inputWidth ), height ( inputHeight )
{
    screenBraille = new wchar_t*[height / 4];

    for(int i = 0; i < height / 4; i++){
        screenBraille[i] = new wchar_t[width / 2];
    }
}

Screen::~Screen()
{
    for(int i = 0; i < height / 4; i++){
        delete screenBraille[i];
    }

    delete screenBraille;

    width = 0;
    height = 0;
}

void Screen::updateScreen(int widthOffset, int heightOffset, bool**& originalImage)
{
    for(int i = 0; i < height / 4; i++){
        for(int j = 0; j < width / 2; j++){
            bool braille[4][2];

            for(int a = 0; a < 4; a++){
                for(int b = 0; b < 2; b++){
                    braille[a][b] = originalImage[heightOffset + 4 * i + a][widthOffset + 2 * j + b];
                }
            }

            screenBraille[i][j] = makeBraille(braille);
        }
    }
}
        
int Screen::getWidth()
{
    return width;
}

int Screen::getHeight()
{
    return height;
}

wchar_t**& Screen::getScreenBraille()
{
    return screenBraille;
}