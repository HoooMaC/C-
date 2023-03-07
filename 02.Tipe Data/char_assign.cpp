#include<iostream>
#include<conio.h>

int main(){
    char a = 1;
    char gerak;
    do{
        std::cout << (int)a << '\t' << a <<std::endl;
        gerak = getch();
        if(gerak == 'w'){
            a--;
        }
        else if(gerak == 'n'){
            a++;
        }
        if(a == 256) break;
    }while(true);
}