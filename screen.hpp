#ifndef __SCREEN__
#define __SCREEN__

#include "braille.hpp"

class Screen{
    private:
        int width;
        int height;

        wchar_t** screenBraille;

        // bool** image;

    public:
        // Screen();

        Screen(int inputWidth, int inputHeight);

        ~Screen();

        void updateScreen(int widthOffset, int heightOffset, bool**& originalImage);

        int getWidth();

        int getHeight();

        wchar_t**& getScreenBraille();

        // bool**& getimage();
};

#endif