#include "Fungsi.h"
#include "Memory.h"

void att::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void att::setCursor(WINBOOL condition){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
	
    cursorInfo.bVisible = condition;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

void att::color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void att::inputCTRL(CTRL temp,CTRL &out, CTRL min,CTRL max){
	if((temp == 'w' or temp == 'W') and out > min){
		out--;
	}else if((temp == 's' or temp == 'S') and out < max){
		out++;
	}
}
void att::border(){
	att::gotoxy(0,0);	std::cout <<'\xC9';	//kiri atas
	att::gotoxy(51,0);	std::cout <<'\xBB';	//kanan atas
	att::gotoxy(0,28);	std::cout <<'\xC8';	//kiri bawah
	att::gotoxy(51,28);	std::cout <<'\xBC';	//kanan bawah
	for(int x = 1; x < 51; x++){
		att::gotoxy(x,0);
		std::cout << '\xCD';
		att::gotoxy(x,28);
		std::cout << '\xCD';
	}
	for(int y = 1; y < 28; y++){
		att::gotoxy(0,y);
		std::cout << '\xBA';
		att::gotoxy(51,y);
		std::cout << '\xBA';
	}
}

void att::line(){
	for(int garis = 0; garis <= 50; garis++){
		std::cout << "\xCD";
	} std::cout << std::endl;
}

void att::lose(){
	system("cls");
	border();
	att::gotoxy(55,14);
	std::cout << "ANDA KALAH" << std::endl;
	system("pause");
}

void att::win(){
	system("cls");
	border();
	att::gotoxy(52,14);
	std::cout << "SELAMAT ANDA MENANG" << std::endl;
}

void att::Loading(){
	att::gotoxy(0,0);
	line();
	att::gotoxy(0,28);
	line();
	att::gotoxy(15,15);
	std::cout<<"Loading";
	for(int x = 0; x < 3; x++){
		std::cout<<" .";
		Sleep(1);
	}
}

void att::menu(CTRL &flow){
	CTRL temp;
	std::string option[9] = {"New Game","Continue","Select Level","Multiplayer","Unlimited Mode",
	"Achievment", "Tutorial", "Save & Load", "Quit"};
	CTRL pos[10] = {22,22,22,20,20,19,21,22,20,24};
	border();
	//	Tampilan Awal
	att::gotoxy(pos[0],8);	std::cout << "WELCOME";
	do{
		for(int i = 0; i < 9; i++){
			(flow-1 == i) ? color(3) : color(7);
			att::gotoxy(pos[i+1],i+9); std::cout << option[i];
		}
		att::color(7);	
		temp =  getch();
		att::inputCTRL(temp,flow,1,9);
	}while(temp != 13);
}

void att::level_list(int level, int &to_level){
	system("cls");
	border();
	att::gotoxy(15,8);
	std::cout << "Pilih level";
	att::gotoxy(15,9);	std::cout << "Level 1 "; if(level <  1)  std::cout << "\t(Locked)";
	att::gotoxy(15,10);	std::cout << "Level 2 "; if(level <  2)  std::cout << "\t(Locked)";
	att::gotoxy(15,11);	std::cout << "Level 3 "; if(level <  3)  std::cout << "\t(Locked)";
	att::gotoxy(15,12);	std::cout << "Level 4 "; if(level <  4)  std::cout << "\t(Locked)";
	att::gotoxy(15,13);	std::cout << "Level 5 "; if(level <  5)  std::cout << "\t(Locked)";
	att::gotoxy(15,14);	std::cout << "Level 6 "; if(level <  6)  std::cout << "\t(Locked)";
	att::gotoxy(15,15);	std::cout << "Level 7 "; if(level <  7)  std::cout << "\t(Locked)";
	att::gotoxy(15,16);	std::cout << "Level 8 "; if(level <  8)  std::cout << "\t(Locked)";
	att::gotoxy(15,17);	std::cout << "Level 9 "; if(level <  9)  std::cout << "\t(Locked)";
	att::gotoxy(15,18);	std::cout << "Level 10"; if(level < 10)  std::cout << "\t(Locked)";
	att::gotoxy(1,27);
	std::cout << "Pilih : ";
	std::cin >> to_level;
}


