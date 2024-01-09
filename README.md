## How to Start

It works on Ubuntu system.

First, Compile these at terminal using command "g++ main.cpp original.cpp braille.cpp -o main.out -lncursesw".

Second, to execute the execute file, input the command into the terminal like "./main.out [ BMP Image File Name ]".

For example, input the command "./main.out test_9.bmp".


===============================================================================================================


본 프로젝트는 점자와 같은 유니코드를 사용하기에 조금 다르게 NCURSES 로 컴파일하여야 한다.

점자를 사용하지 않으면 "g++ main.cpp -o main.out -lncurses" 로 컴파일하면 되지만, 
  이 프로젝트에서는 유니코드를 사용해서 lncurses 가 아닌 lncursesw 를 사용하여, 
  "g++ main.cpp -o main.out -lncursesw" 로 컴파일하여야 한다.

컴파일 후 실행하는 방법은 "./main.out test_9.bmp" 와 같이 "./main.out" 다음에 열고 싶은 단색 비트맵 이미지 파일을 입력해주면 된다.

참고로, 나는 단색 비트맵 이미지를 윈도우의 그림판을 활용하여 생성하였다.

8의 배수로 이미지의 가로 픽셀 수를 설정하고 ( 예를 들어, 128 x 128 ) ( 세로 픽셀 수는 상관없다. ) 원하는 그림을 그린다. 

그리기를 마치고 '다른 이름으로 저장' 을 클릭한 후 파일 형식을 '단색 비트맵' 으로 설정하여 저장하면 된다.
