#ifndef __ORIGINAL__
#define __ORIGINAL__

class original{
    private:
        int width = 0;
        int height = 0;

        bool** image;

    public:
        original();
        
        ~original();

        void loadImage(const char * location);

        int getWidth();

        int getHeight();

        bool**& getImage();
};

#endif