#include <iostream>

int main(){
    char a = 'a';
    int b = 5;
    std::cout <<"a = " << a << std::endl;
    std::cout <<"b = " << b << std::endl;
    std::cout <<"a = " << (int)a << std::endl;
    std::cout <<"b = " << (char)b << std::endl;

    int x = 5, y = 10, z = 32;
    std::cout << (float)x + (float)y + (float)z / 3 << std::endl;
    std::string c = "gunawan";
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(c[0]) << std::endl;
}