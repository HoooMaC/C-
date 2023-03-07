#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <mutex>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void print_centered(const std::string &s, int start, int height, int width){
    gotoxy(start,height);
    int spaces = (width - s.length()) / 2;
    std::cout << std::setfill(' ') << std::setw(spaces + s.length()) << std::right << s << std::endl;
}

class Border{
    public:
        Border* outer(){
            gotoxy(0,0);	std::cout <<'\xC9';	//kiri atas
            gotoxy(50,0);	std::cout <<'\xBB';	//kanan atas
            gotoxy(0,30);	std::cout <<'\xC8';	//kiri bawah
            gotoxy(50,30);	std::cout <<'\xBC';	//kanan bawah
            int x1=0,x2=50,y1=0,y2=30;
            for(int xsum = 0; xsum < 25; xsum++){
                x1++;
                x2--;
                if(xsum <= 14){
                    y1++;
                    y2--;
                    gotoxy(0,y1);  std::cout << '\xBA';
                    gotoxy(50,y1); std::cout << '\xBA';
                    gotoxy(0,y2);  std::cout << '\xBA';
                    gotoxy(50,y2); std::cout << '\xBA';
                }
                gotoxy(x1,0); std::cout << '\xCD';
                gotoxy(x1,30);std::cout << '\xCD';
                gotoxy(x2,0); std::cout << '\xCD';
                gotoxy(x2,30);std::cout << '\xCD';
            }
            return this;
        }

        Border* mid_vertical(){
            for(int i = 1; i < 30; i++){
                gotoxy(25,i);   std::cout << i;
            }
            return this;
        }

        Border* shelf(){
            gotoxy(25,0); std::cout << '\xCB';
            for(int i = 1; i < 30; i++){
                if((i % 5) == 0){
                    gotoxy(0,i); std::cout << '\xCC';
                    gotoxy(50,i); std::cout << '\xB9';
                    for(int j = 1; j < 50; j++){
                        gotoxy(j,i); std::cout << '\xCD';
                    }
                    gotoxy(25,i); std::cout << '\xCE';
                }
                else{
                    gotoxy(25,i);   std::cout << '\xBA';
                }
            }
            gotoxy(25,30); std::cout << '\xCA';
            return this;
        }
};


int main(){
    std::string text = "Hello World";
    Border a;
    a.outer()->shelf();
    gotoxy(0,31);
    return 0;
}