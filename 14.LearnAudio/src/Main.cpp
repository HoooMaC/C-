#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    
    cout << "Hello World" << endl;
    PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME);
    return 0;
}