#ifndef __SYSTEM__
#define __SYSTEM__

#include "original.hpp"
#include "screen.hpp"

class System{
    private:
        char * bmpFileName;
        int settedWidth;
        int settedHeight;

    public:
        System(const char * bmpFileName, int settedWidth, int settedHeight);
        
        ~System();

        void startSystem();
};

#endif