#include <iostream>
#include <fstream>


enum save_flow{menu, newAcc, save, load, deleteAcc, quit};

namespace Acc{
    void open_file(std::fstream &file, std::string namafile){
        file.open(namafile, std::ios::out | std::ios::in);
        if(file.fail()){
            std::cout << "File is not found" << std::endl;
            std::cout << "Making a new file" << std::endl;
            file.close();
            file.open(namafile, std::ios::trunc | std::ios::out | std::ios::in);
        }else   std::cout << "Data berhasil di buka" << std::endl;
    }

    void displayData(std::fstream &file){
        std::string tempstr;
        std::cout << "no.\tnick\tlevel" << std::endl;
        for(int number = 1; !file.eof();number++){
            std::cout << number << '\t';
            std::getline(file,tempstr);
            std::cout << tempstr << '\t';
            std::getline(file,tempstr);
            std::cout << tempstr << std::endl;
        }
    }

    void load_data(std::fstream &file, std::string &nick, int &level, int &number){
        file.seekg(0, std::ios::beg);
        for(int x = 1; x <= number; x++){
            file >> nick;
            file >> level;
        }
    }

    void newAccount(){
    }
    
    void tambah_data(){
    }
}


int main(){
    std::string current_nick = "guest" ;
    int current_level = 1 ;
    std::fstream file;
    Acc::open_file(file,"data");
    int pilihan = 0;
    std::string is_choose;
    do{
        // system("cls");
        switch (pilihan) {
        case menu:
            std::cout << "nick : " << current_nick << std::endl;
            std::cout << "level : " << current_level << std::endl;
            std::cout << "Save & Load Menu :" << std::endl
                      << "1. New Account" << std::endl
                      << "2. Save" << std::endl
                      << "3. Load Account" << std::endl
                      << "4. Delete Account" << std::endl;
            std::cin >> pilihan;
            break;
        case newAcc:
            
            break;
        case save://update
            break;
        case load: {//selesai      
            int number;
            Acc::displayData(file);
            std::cout << "choose account : ";
            std::cin >> number;
            Acc::load_data(file,current_nick,current_level,number);
            pilihan = 0;
            break;
        }  
        case deleteAcc:
            break;
        case quit:
            std::cout << "Are you sure do you want to quit : <y/n>" << std::endl;
            std::cin >> is_choose;
            if(!(is_choose == "y") or !(is_choose == "Y"))    pilihan = 0;
            break;
        default:
            break;
        }
    }while(pilihan != 5);
    file.close();
    return 0;
}