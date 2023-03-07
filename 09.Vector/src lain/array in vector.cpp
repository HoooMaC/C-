#include <iostream>
#include <vector>
#include <array>
#include <fstream>

int main(){
    std::vector<std::array<int,2>> a;
    a.reserve(10);
    int n =  a.capacity();//row
    int m = a[0].size();//column
    std::cout << "row "<< n << std::endl;
    std::cout << "column " << m << std::endl;
    std::cout << "=============================" << std::endl;
    //open the file
    std::ifstream input;
    input.open("number.txt");
    if(input.is_open()){
        std::cout << "file opened" << std::endl;
        std::cout << "=============================" << std::endl;
    }
    //we try to reserve the 
    for(int column = 0; column < m; column++){
        for(int row = 0; row < n; row++){
            // input >> temp;
            input >> a[row][column];
            std::cout << row << ' ' << column << ' ' << a[row][column] << std::endl;
            // a.at(row)[column] = temp;
            // a[row][column] = temp;
        }
        std::cout << std::endl;
    }
    //  for(int column = 0; column < a[9].size(); column++){
    //     for(int row = 0; row < a.size(); row++){
    //         std::cout << a[row][column] << ' ';
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << std::endl;
    input.close();
    return 0;
} 