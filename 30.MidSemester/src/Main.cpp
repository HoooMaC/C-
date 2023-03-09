#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Subject{
public:
    std::string title;
    int score;
};

class Student {
public:
    std::string name;
    std::string id;

    //perlu di alokasikan memori
    Subject *item;
};


int main(){
    Student *data = new Student;
    std::string filename = "MK-A";
    filename = "data/" + filename + ".csv";
    
    std::ifstream input;
    input.open(filename);
    if(!input.is_open()){
        std::cout << "Cannot open the file\n";
        return 1;
    }
    /*
    int counter = 0;
    while(!input.eof())
    {
        //lakukan pencarian apakah student sudah ada atau belum

        Student temp;

        std::getline(input,temp.name,';');
        std::getline(input,temp.id,';');
        
        temp.item->title = filename;
        input >> temp.item->score;

        counter++;
        std::cout << counter << '.';
        std::cout << temp.name << '\n';
        std::cout << temp.id << '\n';
        std::cout << temp.item->title << '\n';
        std::cout << temp.item->score << '\n';

    }
    */
    delete data;
    return 0;

} 