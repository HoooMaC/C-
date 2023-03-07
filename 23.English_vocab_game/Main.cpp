#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <Windows.h>

class Player{
    public:
        int score;
        std::string name;
        Player(){
            Player::score = 0;
        }
};
class Play{
    public:
        int number;
        std::vector<int> index;
        std::vector<std::array<std::string,3>> word;
        std::ifstream insert;

        Play(std::string filename){

            filename.insert(0,"./vocab/");
            Play::insert.open(filename, std::ios::in);

            if(!Play::insert.is_open()){
                std::cout << "file can't opened" << std::endl;
                return;
            }

            Play::insert >> Play::number;

            word.resize(Play::number);

            Play::input_word();

            Play::generate_index();
            
        }

        void generate_index(){
            index.resize(Play::number);
            for(int i = 0; i < Play::number; i++){
                index[i] = i;
            }

            srand(time(0));
            std::random_shuffle(index.begin(), index.end());

        }

        void input_word(){
            for(int i = 0,j = Play::word.capacity(); i < j ; i++){
                std::string tempA, tempB, tempC;
                Play::insert >> tempA;
                Play::insert >> tempB;
                // Play::insert.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Play::insert.ignore();
                std::getline(Play::insert,tempC);
                std::transform(tempC.begin(), tempC.end(), tempC.begin(), ::tolower);
                Play::word[i][0] = tempA;
                Play::word[i][1] = tempB;
                Play::word[i][2] = tempC;
            }
        }

        void question(int n){
            std::string answer;
            std::cout << "What is the meaning of : " << Play::word[Play::index[n]][0] <<std::endl;
            std::cout << "Word Class : " << Play::word[Play::index[n]][1] << std::endl;
            std::cout << "Answer : ";
            std::getline(std::cin,answer);
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if(answer == Play::word[Play::index[n]][2]){
                std::cout << "Correct" << std::endl;
            }
            else {
                std::cout << "Oops! Wrong answer" << std::endl;
            }
            
        }

        void show_vocab(){
            for(int i = 0,j = Play::word.capacity(); i < j ; i++){
                std::cout << Play::word[i][0] << ' ';
                std::cout << Play::word[i][1] << std::endl;
                std::cout << Play::word[i][2] << std::endl;
            }
        }

        void show_index(){
            for(int i = 0, j = index.capacity(); i < j; i++){
                std::cout << Play::index[i] << std::endl;
            }
        }

        ~Play(){
            Play::insert.close();
        }

};

int main(){
    int score = 0;
    Play coba1("TOEFL_part1.txt");
    for(int i = 0; i < 10; i++){
        coba1.question(i);
    }
    return 0;
}