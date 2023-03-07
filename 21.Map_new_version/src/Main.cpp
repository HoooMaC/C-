#include <Windows.h>
#include <iostream>
#include <vector>
#include <array>
#include <fstream>

typedef unsigned char CTRL;
class Map{
    private:
    public:
        std::vector<std::array<char, 21>> world;

        Map(){
            this->world.reserve(51);
        }

        void generate_map(){
            //column
            for(int k = 0, l = world[0].size(); k < l; k++){
                //row
                for(int i = 0, j = world.capacity(); i < j; i++){
                    if(i == 1 and k == 1){
                        this->world[i][k] = '\xC9';
                    }
                    //Pojok kiri bawah
                    else if(i == 1 and k == l-1){
                        this->world[i][k] = '\xC8';
                    }
                    //Pojok kanan atas
                    else if(i == j-1 and k == 1){
                        this->world[i][k] = '\xBB';
                    }
                    //Pojok kanan bawah
                    else if(i == j-1 and k == l-1){
                        this->world[i][k] = '\xBC';
                    }
                    else if(i == 0 or k == 0){
                        this->world[i][k] = ' ';
                    }
                    else if(i == 1 or i == j-1){
                        this->world[i][k] = '\xBA';
                    }
                    else if(k == 1 or k == l-1){
                        this->world[i][k] = '\xCD';
                    }
                    else{
                        this->world[i][k] = ' ';
                    }
                }
            }
        }

        void generate_obs(){
            std::fstream input;
            input.open("x-map.txt");
            if(!input.is_open()){
                std::cout << "data tidak berhasil dibuka";
                return;
            }
            while(!input.eof()){
                short x, y;
                input >> x >> y;
                this->world[x][y] = '*';

            }
            input.close();
        }

        void print_map(){
            for(int k = 0, l = world[0].size(); k < l; k++){
                for(int i = 0, j = world.capacity(); i < j; i++){
                    std::cout << world[i][k];
                }
                std::cout << std::endl;
            }
        }
};



int main(){
    Map coba1;
    coba1.generate_map();
    coba1.generate_obs();
    coba1.print_map();
    std::cout << coba1.world.capacity() << std::endl;
    std::cout << coba1.world[1].size() << std::endl;
    return 0;
}