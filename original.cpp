#include "original.hpp"
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

Original::Original()
{

}

Original::~Original()
{
    for(int i = 0; i < height; i++){
        delete image[i];
    }

    delete image;

    width = 0;
    height = 0;
}

void Original::loadImage(const char * location)
{
    int fd = open(location, O_RDONLY);

    if(fd < 0){
        std::cout << "Image open error!" << endl;

        exit(-2);
    }

    lseek(fd, 18, SEEK_SET);        // Image 의 가로, 세로 픽셀 수는 처음에서 18 번째 Byte 에서부터 있다.
    read(fd, &width, sizeof(int));    // Bit 단위로 다루어야 하지만, 파일 입출력으로는
    read(fd, &height, sizeof(int));   // Byte 단위로밖에 다룰 수 없다.

    // vector<vector<bool>> image(image_height, vector<bool> (image_width));       // 2차원 vector 사용.

    image = new bool*[height];

    for(int i = 0; i < height; i++){
        image[i] = new bool[width];
    }
    
    lseek(fd, 0, SEEK_END);        // 이미지 파일의 마지막으로 이동.

    unsigned char temp = 0;

    for(int i = 0; i < height; i++){  // 단색 비트맵 파일에는 원본 이미지를 아래로 한 번 뒤집어진 상태로 저장됨을 고려.
        lseek(fd, -(width / 8), SEEK_CUR);    // 읽으려는 이미지의 row 의 첫 번째 픽셀로 이동.

        for(int j = 0; j < width; j = j + 8){ // 읽으면 해당 row 의 마지막 번째 픽셀로 이동.
            read(fd, &temp, sizeof(unsigned char)); 
            
            int offset = 0;
            unsigned char temp_and = 128;

            while(offset < 8){
                unsigned char comp = temp & temp_and;

                if(comp == 0)
                    image[i][j + offset] = false;
                else
                    image[i][j + offset] = true;

                offset++;
                temp_and /= 2;
            }
        }

        lseek(fd, -(width / 8), SEEK_CUR);    // 읽었던 이미지의 첫 번째 픽셀로 이동.
    }

    close(fd);

    return;
}

int Original::getWidth()
{
    return width;
}

int Original::getHeight()
{
    return height;
}

bool**& Original::getImage()
{
    return image;
}