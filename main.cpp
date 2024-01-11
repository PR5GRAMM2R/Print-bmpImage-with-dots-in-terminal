// #include <ncursesw/curses.h>     // "g++ main.cpp system.cpp screen.cpp original.cpp braille.cpp -o main.out -lncursesw" 로 터미널 컴파일 필수.
// #include <ncurses.h>             // 2020203011 배주환
#include <iostream>
#include <stdio.h>
#include "system.hpp"

using namespace std;

int main(int argc, char const * argv[])
{
    std::locale::global(std::locale(""));   // Set program's locale to default for using Unicode.
    std::wcout.imbue(std::locale());

    if(argc < 4){
        std::cout << "Insert Error : a.txt [ Bitmap Image File ] [ Screen Width ] [ Screen Height ]" << endl;

        exit(-1);
    }

    std::cout << argv[1] << endl;

    System sys(argv[1], atoi(argv[2]), atoi(argv[3]));

    sys.startSystem();

    // for(int i = 0; i < screenHeight; i++){
    //     for(int j = 0; j < screenWidth; j++){
    //         if(screenImage[i][j] == true){
    //             cout << "*";
    //         }
    //         else{
    //             cout << " ";
    //         }
    //     }

    //     cout << endl;
    // }

    return 0;
}
