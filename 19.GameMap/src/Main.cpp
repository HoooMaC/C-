#include <iostream>
#include <conio.h>
#include <array>
#include <windows.h>
#include "Fungsi.h"

class Map{
    public:
        std::array<std::array<char,50>,100> map;
        int columnMin;
        int columnMax;
        int rowMin;
        int rowMax;
        int nColumn = sizeof(map[0]);
        int nRow =  sizeof(map) / sizeof(map[0]);
        void generateMap(){
            for(int column = 0; column < Map::nColumn; column++){
                for(int row = 0; row < Map::nRow; row++){
                    if((row == 1 and column == 1) or (row == Map::nRow-1 and column == Map::nColumn-1) or (row == 1 and column == Map::nColumn-1) or (row == Map::nRow-1 and column == 1)){
                        map[row][column] = '#';
                    }
                    else if(column == 1 or column == Map::nColumn-1){
                        map[row][column] = '=';
                    }
                    else if(row == 1 or row == Map::nRow-1){
                        map[row][column] = '|';
                    }
                    else {
                        map[row][column] =  ' ';
                    } 

                }
            }
        }
        void single_control(){
            char move = getch();
            if((move == 'w' or move == 'W') and Map::columnMin > 1){
                Map::columnMin--;
            }
            else if((move == 's' or move == 'S') and Map::columnMax < nColumn){
                Map::columnMin++;
            }
            else if((move == 'a' or move == 'A') and Map::rowMin > 1){
                Map::rowMin--;
            }
            else if((move == 'd' or move == 'D') and Map::rowMax < nRow){
                Map::rowMin++;
            }
            updateMax();
        }
        void updateMax(){
            Map::columnMax = columnMin + 20;
            Map::rowMax = rowMin + 50;
        }
        void printMap(){
           att::gotoxy(0,0);
           //print all
            // for(int column = 0; column < Map::nColumn; column++){
            //     for(int row = 0; row < Map::nRow; row++){
            //         std::cout << map[row][column];
            //     }
            //     std::cout << std::endl;
            // }
            for(int column = Map::columnMin; column < Map::columnMax; column++){
                for(int row = Map::rowMin; row < Map::rowMax; row++){
                    std::cout << map[row][column];
                }
                std::cout << std::endl;
            }
        }
        void printValue(){
            att::gotoxy(0,25);
            std::cout << columnMin << "    ";;
            att::gotoxy(0,26);
            std::cout << columnMax << "    ";;
            att::gotoxy(0,27);
            std::cout << rowMin << "    ";
            att::gotoxy(0,28);
            std::cout << rowMax << "    ";;
        }
    public:
        Map(){
            Map::rowMin = 1;
            Map::columnMin = 1;
            generateMap();
            updateMax();

        }
};



int main(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
	
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
    system("cls");
    Map halo;
    while(true){
        // system("cls");
        halo.printMap();
        halo.printValue();
        halo.single_control();

    }
    // std::cout << sizeof(halo.map[0]) << std::endl;
    return 0;
}