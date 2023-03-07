#include <iostream>

int main(){
    int menu = 0;



    switch (menu)
    {
    case 1:
        /* code */
        break;
    
    default:
        std::cout << "1. Play\n"
                  << "2. Select level\n"
                  << "3. Show Vocab\n"
                  << "4. Quit\n";
        break;
    }
    return 0;
}