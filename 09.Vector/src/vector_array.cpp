#include <vector>
#include <array>
#include <iostream>

int main(){
    std::vector<std::array<int,50>> item;
    std::cout << item.capacity();
    // item[0][0] = 43;
    // std::cout << item[0][0];
}