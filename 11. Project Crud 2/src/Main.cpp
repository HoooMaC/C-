#include <iostream>
#include <fstream>
#include <vector>

enum save_flow{menu, display, newAcc, save, load, deleteAcc, quit};
class DBase{
    public:
        std::vector<std::string>nick;
        std::vector<int>level;
        std::fstream file;
        std::string namafile;
        

        DBase(std::string namafile){
            DBase::namafile = namafile;
            DBase::nick.reserve(10);
            DBase::level.reserve(10);
            DBase::file.open(DBase::namafile, std::ios::out | std::ios::in);
            if(DBase::file.fail()){
                std::cout << "File is not found" << std::endl;
                std::cout << "Making a new file" << std::endl;
                DBase::file.close();
                DBase::file.open(namafile, std::ios::trunc | std::ios::out | std::ios::in);
            }else   std::cout << "Data berhasil di buka" << std::endl;
            readData();           
        }

        void readData(){
            int tempint, dataSize = 0;
            std::string tempstr;
            DBase::file.seekg(0, std::ios::beg);
            for(int x = 0; !DBase::file.eof(); x++){
                if( x == DBase::nick.capacity()) break;
                DBase::file >> tempstr;
                if(tempstr == "End$") break;
                DBase::nick.push_back(tempstr);
                DBase::file >> tempint;
                DBase::level.push_back(tempint);
            }std::cout << "loop selesai" << std::endl;
        }

        void displayData(){
            system("cls");
            std::cout << "no.\tnick\tlevel" << std::endl;
            for(int x = 0; x < DBase::nick.size(); x++){
                std::cout << x+1 << '\t' << DBase::nick.at(x) << '\t' << DBase::level.at(x);
                std::cout << std::endl;
            }
        }

        void newAccount(){
            std::string newAccount;
            if(DBase::nick.size() == DBase::nick.capacity()){
                std::cout << "the memory is full" << std::endl;
                std::cout << "choose the account to overwrite" << std::endl;
                displayData();
                int number;
                std::cin >> number;
                std::cout << "Insert nickname : ";
                std::cin >> newAccount;
                DBase::nick.at(number-1) = newAccount;
                DBase::level.at(number-1) = 1;
            }else {
                std::cout << "Insert nickname : ";
                std::cin >> newAccount;
                DBase::nick.push_back(newAccount);
                DBase::level.push_back(1);
                std::cout << "creat accout succes" << std::endl;
            }
        }

        void saveData(std::string nick, int level){//update //selesai
            // pertama nampilin data dulu
            displayData();
            int number;
            std::cout << "Choose memory you want to overwrite : ";
            std::cin >> number;
            if(number > DBase::nick.size()){ 
                std::cout << "Account doesn't exist" << std::endl;
                system("pause");
            }else{
                DBase::nick.at(number-1) = nick;
                DBase::level.at(number-1) = level;
            }
        }
        
        void loadData(std::string &nick, int &level){//selesai
            //pertama nampilin data dulu
            displayData();
            int number;
            std::cout << "Choose account you want to load : ";
            std::cin >> number;
            nick = DBase::nick.at(number-1);
            level = DBase::level.at(number-1);
            std::cout << "Load Account succes" << std::endl;
        }

        void deleteData(){
            //pertama nampilin data dulu
            displayData();
            std::cout << "Choose account you want to delete : ";
            int number;
            std::cin >> number;
            number--;
            DBase::nick.erase(nick.begin() + number);
            DBase::level.erase(level.begin() + number);
        }

        ~DBase(){
            DBase::file.close();
            displayData();
            DBase::file.open(DBase::namafile, std::ios::trunc | std::ios::out);
            for(int x = 0; x < DBase::nick.size(); x++){
                DBase::file << DBase::nick.at(x) << std::endl;
                DBase::file << DBase::level.at(x) << std::endl;
            }
            DBase::file << "End$";
            DBase::file.close();
            // //nanti ini dihapus ya
            // std::cout << "===================" << std::endl;
            // std::cout << "class ini dihapus" << std::endl;
            // std::cout << "capacity : "<< DBase::nick.capacity() << std::endl;
            // std::cout << "size : " << DBase::nick.size() << std::endl;
            // std::cout << "max size : " << DBase::nick.max_size() << std::endl;
            // std::cout << "last " << DBase::nick.back() << std::endl;
        }

};

int main(){
    DBase kar("data");
    std::string current_nick = "guest" ;
    int current_level = 1 ;
    int pilihan = 0;
    std::string is_choose;
    do{
        switch (pilihan) {
        case menu:
            system("cls");
            std::cout << "nick : " << current_nick << std::endl;
            std::cout << "level : " << current_level << std::endl;
            std::cout << "Save & Load Menu :" << std::endl
                      << "1. Show Account list" << std::endl
                      << "2. New Account" << std::endl
                      << "3. Save" << std::endl
                      << "4. Load Account" << std::endl
                      << "5. Delete Account" << std::endl;
            std::cin >> pilihan;
            std::cin.ignore();
            break;
        case display: 
            kar.displayData();
            pilihan = 0;
            std::cin.get();
            break;
        case newAcc:
            kar.newAccount();
            pilihan = 0;
            break;
        case save://update
            kar.saveData(current_nick,current_level);
            pilihan = 0;
            break;
        case load: {//selesai    
            kar.loadData(current_nick, current_level);
            pilihan = 0;
            break;
        }  
        case deleteAcc:
            kar.deleteData();
            pilihan = 0;
            break;
        case quit:
            std::cout << "Are you sure do you want to quit : <y/n>" << std::endl;
            std::cin >> is_choose;
            if(!(is_choose == "y") or !(is_choose == "Y"))    pilihan = 0;
            break;
        default:
            break;
        }
    }while(pilihan != quit);
    return 0;
}