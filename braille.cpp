#include "braille.hpp"

#include <iostream>
#include <locale>
#include <codecvt>
#include <sys/types.h>

using namespace std;

wchar_t makeBraille(bool braille[4][2])
{
    std::locale::global(std::locale(""));   // Set program's locale to default for using Unicode.
    std::wcout.imbue(std::locale());

    wchar_t temp = U'\u2800';

    bool compare = false;

    //unsigned short temp = 2800;

    if(braille[0][0] == compare){
        temp += 1;
    }
    if(braille[0][1] == compare){
    temp += 8;
    }
    if(braille[1][0] == compare){
        temp += 2;
    }
    if(braille[1][1] == compare){
        temp += 16;
    }
    if(braille[2][0] == compare){
        temp += 4;
    }        
    if(braille[2][1] == compare){
        temp += 32;
    }
    if(braille[3][0] == compare){
        temp += 64;
    }
    if(braille[3][1] == compare){
        temp += 128;
    }

    return temp;                 
}