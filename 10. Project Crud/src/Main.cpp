#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct DataAcc{
    int pk;
    string nick;
    int level;
};

namespace Data{
    fstream data;

    int get_option(){
            int input;
            system("clear");
            system("cls");
            cout << "\nProgram CRUD data akun" << endl;
            cout << "=============================" << endl;
            cout << "1. Tambah data akun" << endl;
            cout << "2. Tampilkan data akun" << endl;
            cout << "3. Ubah data akun" << endl;
            cout << "4. Hapus data akun" << endl;
            cout << "5. Selesai" << endl;
            cout << "=============================" << endl;
            cout << "pilih [1-5]? : ";
            cin >> input;
            cin.ignore();
            return input;
    }

    void checkdata(){
        data.open("data.bin", ios::out | ios::in | ios::binary);
        if(!data.is_open()){
            cout << "Data tidak ditemukan" << endl;
            cout << "Membuat data baru" << endl;
            data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
        }
    }

    int getdata_size(){
        int start, end;
        data.seekg(0,ios::beg);
        start = data.tellg();
        data.seekg(0,ios::end);
        end = data.tellg();
        return (end-start)/sizeof(DataAcc);
    }

    void readData(DataAcc &readAccount, int posisi){
        data.seekg((posisi - 1)*sizeof(DataAcc),ios::beg);
        data.read(reinterpret_cast<char*>(&readAccount),sizeof(DataAcc));
    }

    void writeData(int posisi, DataAcc &newAccount){
        data.seekp((posisi - 1)*sizeof(DataAcc), ios::beg);
        data.write(reinterpret_cast<char*>(&newAccount),sizeof(DataAcc));
    }

    void addDataMahasiswa(){

        DataAcc newAccount, lastAccount;

        int size = getdata_size();
        
        cout << "ukuran data : " << size << endl;

        if(size == 0){
            newAccount.pk = 1;
        } else {
            readData(lastAccount, size);
            cout << "pk = " << lastAccount.pk << endl;
            newAccount.pk = lastAccount.pk + 1;
        }

        cout << "Nick: ";
        getline(cin, newAccount.nick);
        cout << "Level: ";
        cin >> newAccount.level;

        writeData(size+1, newAccount);
    }
    void displayDataMahasiswa(DataAcc &showAccount){
	    int size = getdata_size();
        cout << "no.\tpk.\tnic.\tLevel" << endl;
        for(int i = 1; i <= size; i++){
            readData(showAccount, i);
            cout << i << "\t";
            cout << showAccount.pk << "\t";
            cout << showAccount.nick << "\t";
            cout << showAccount.level << endl;
	    }
    }
}


int main(){

    DataAcc data1;
    int pilihan = 0;
    Data::checkdata();
    do{
        switch (pilihan) {
            case 0 :    
                pilihan = Data::get_option();
                break;
            case 1 :    
                cout << "tambah data" << endl;
                Data::addDataMahasiswa();
                pilihan = 0;
                break;
            case 2 :    
                cout << "tampilkan data" << endl;
                Data::displayDataMahasiswa(data1);
                system("pause");
                pilihan = 0;
                break;
            case 3 :    cout << "Ubah data" << endl;
                break;
            case 4 :    cout << "Hapus data" << endl;
                break;
            case 5 :    cout << "Quit" << endl;
                break;
            default:    break;
        }
    }while(pilihan!=5);

}