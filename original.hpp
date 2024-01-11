#ifndef __ORIGINAL__
#define __ORIGINAL__

class Original{
    private:
        int width = 0;
        int height = 0;

        bool** image;

        // bool* image;

    public:
        Original();
        
        ~Original();

        void loadImage(const char * location);

        int getWidth();

        int getHeight();

        bool**& getImage();
};

#endif