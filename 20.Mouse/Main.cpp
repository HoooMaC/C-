#include <iostream>
#include <Windows.h>
#include "Fungsi.h"
#define WM_LBUTTONDOWN  0x0201
int main(){
    bool key = false;
    while(!key){
        POINT mousepos;
        GetCursorPos(&mousepos);
        // system("cls");
        att::gotoxy(0,0);
        std::cout << mousepos.x << "   ";
        att::gotoxy(0,1);
        std::cout  << mousepos.y << "   ";
        if(GetAsyncKeyState(WM_LBUTTONDOWN)){
            key  = true;
            std::cout << "left click is pressed end program" << std::endl;
        }
    }
    return 0;
}