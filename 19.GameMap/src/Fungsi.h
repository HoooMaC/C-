#pragma once
#include<iostream>
#include<thread>
#include<conio.h>
#include<sstream>
#include<conio.h>
#include<string>
#include<cstdlib>
#include<fstream>
#include<unistd.h>
#include<windows.h>
#include<vector>
#include<array>
#include<mutex>
// using namespace std;
typedef unsigned char CTRL;
enum no_level{Level_List = 0, Level1, Level2, Level3, Level4, Level5, Level6, Level7, Level8, Level9,Level10};
enum flow{NewGame = 1, Continue, SelectLevel, Multiplayer, Unlimited, Achievment, Tutorial, SaveLoad, Quit};
enum save_menu{ShowList = 1,NewAcc,Save,Load,Delete};
namespace att{
	void gotoxy(int, int);
	void setCursor(WINBOOL);
	void color(int color);
	void inputCTRL(CTRL temp,CTRL &out, CTRL min,CTRL max);
	void border();
	void line();
	void lose();
	void win();
	void Loading();
	void menu(CTRL &);
	void level_list(int, int &);
}


