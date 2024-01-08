#ifndef __BRAILLE__
#define __BRAILLE__

/*
        --- Braille Unicode (점자 유니코드) ---

        Start from '/u2800'.
            ( 1   )  ( 8   )
            ( 2   )  ( 16  )
            ( 4   )  ( 32  )
            ( 64  )  ( 128 )

        2 * 4 행렬을 가지고 각 부분마다 match 되는 부분에 해당 위치의 수를 더해야 함.
    */

wchar_t makeBraille(bool braille[4][2]);

#endif