/*Jika program error kemungkinan karena compiler
Ini link untuk jaga-jaga jika program tidak bisa dicompile*/
/*Memasukkan header yang digunakan*/
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
/*Preprocessing directive*/
#define corner_RU '\xBB'
#define corner_RD '\xBC'
#define corner_LU '\xC9'
#define corner_LD '\xC8'
#define verti '\xBA'
#define hori  '\xCD'
/*Prototype Function*/
void gotoxy(int x, int y);
void makeborder();
void color(int color);
void inputCTRL(int temp, int &out, int min, int max);
void print_centered(const std::string &s,int y);
/*Prototype class*/
class Node{
private:
    Node *tail = NULL;
    const char* title;
public:
    int data;
    Node *next;
    Node* makeNew(int value);
    Node* getTail();
    void printAll();
    void addLast(int value);
    void addBegin(int value);
    void insert(int pos, int value);
    void shift_right();
    void shift_left();
    void deleteLast();
    void deleteBeg();
    void deleteI(int pos);
    void deleteAll();
    ~Node();
};
/*membuat penomoran*/
enum menu{Print=1,Insert,Delete,Shift,Quit};
int main(){
    /*deklarasi variable untuk mengatur alur program
    flow untuk switch pada main menu
    insert_flow untuk switch insert
    delete_flow untuk switch delete
    shift_flow untuk switch shift
    buffer untuk menyimpan inputan dari keyboard sementara*/
    int flow = 0, insert_flow = 0, delete_flow = 0,shift_flow = 0, buffer = 0;
    system("cls");
    makeborder();
    /*menampilkan nama*/
    print_centered("Name : Gunawan",9);
    print_centered("NIM : 225150307111042",10);
    gotoxy(2,19);
    system("pause");
    /*Membuat linked list*/
    Node list_data;
    do{
        
        system("cls");
        switch (flow)
        {
        /*case untuk masuk menu print semua data dari linked list*/
        /*Print mewakilkan angka 1*/
        case Print:
            makeborder();
            list_data.printAll();
            gotoxy(2,19);
            system("pause");
            flow = 0;
            break;
        /*case untuk masuk ke menu Insert */
        /*Insert mewakilkan angka 2*/
        case Insert:
            /*mereset nilai insert_flow ke 0 agar masuk ke case default*/
            insert_flow = 0;
            system("cls");
            do{
                int value;
                makeborder(); 
                /*Sub switch atau nested untuk membuat menu insert*/
                switch (insert_flow)
                {
                case 1:
                    system("cls");
                    makeborder(); 
                    /*Meminta input dari user*/
                    print_centered("Enter the value",10);
                    gotoxy(25,11);
                    std::cin >> value;
                    /*Menjalankan fungsi untuk memasukkan nilai yang 
                    sudah dimasukkan ke index terakhir*/
                    list_data.addBegin(value);
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    insert_flow = 4;
                    break;
                case 2:
                    system("cls");
                    makeborder(); 
                    /*Meminta input dari user*/
                    print_centered("Enter the value",10);
                    gotoxy(25,11);
                    std::cin >> value;
                    /*Menjalankan fungsi untuk memasukkan nilai yang 
                    sudah dimasukkan ke index terakhir*/
                    list_data.addLast(value);
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    insert_flow = 4;
                    break;
                case 3:
                    system("cls");
                    makeborder(); 
                    int number;
                    /*Meminta input dari user*/
                    print_centered("Enter the value",9);
                    gotoxy(25,10);
                    std::cin >> number;
                    /*Pengecekan kondisi linked list, linkedlist kosong
                    maka akan nilai inputan akan dimasukkan ke index 
                    pertama dengan fungsi addBegin()*/
                    if(list_data.getTail() == NULL){
                        system("cls");
                        print_centered("Empty List",9);
                        makeborder(); 
                        print_centered("Entering number to first index",10);
                        gotoxy(2,19);
                        system("pause");
                        list_data.addBegin(number);
                    }
                    else{
                        makeborder(); 
                        /*Meminta user menentukan pada index keberapa
                        nilai akan dimasukkan*/
                        print_centered("Enter the number of index which want to insert",11);
                        gotoxy(25,12);
                        int index;
                        std::cin >> index;
                        /*Menjalankan fungsi untuk memasukkan nilai ke index
                        yang sudah ditentukan*/
                        list_data.insert(index,number);
                    }
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    insert_flow = 4;
                    break;
                default:
                    /*Sub menu pada switch Insert untuk meminta pilihan
                    dari user*/
                    makeborder();
                        do{
                            std::string selection[4] = {"Insert in Beginning","Insert in Last","Insert in Index","Back to Menu"};
                            /*Perulangan untuk menampilkan semua pilihan atau opsi*/
                            for(int i = 0; i < 4; i++){
                                (insert_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            /*Meminta input kontrol dari user*/
                            buffer = getch();
                            /*Fungsi yang membaca, mengatur, dan menjaga nilai flow agar tidak melebihi batas*/
                            inputCTRL(buffer,insert_flow,1,4);
                        }while(buffer != 13);
                    break;
                }
            }while(insert_flow != 4);
            /*Mereset nilai agar kembali ke menu utama*/
            flow = 0;
            color(7);
            gotoxy(1,29);
            break;
        /*case untuk masuk ke menu delete */
        /*Delete mewakilkan angka 3*/
        case Delete:
            /*Mereset delete_flow ke 0 agar masuk ke case default*/
            delete_flow = 0;
            system("cls");
            do{
                /*Sub switch untuk masuk ke menu delete*/
                makeborder(); 
                switch (delete_flow)
                {
                case 1:
                    /*Menjalankan fungsi untuk menghapus nilai pada index 0*/
                    list_data.deleteBeg();
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    delete_flow = 5;
                    break;
                case 2:
                    /*Menjalankan fungsi untuk menghapus nilai pada index terakhir*/
                    list_data.deleteLast();
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    delete_flow = 5;
                    break;
                case 3:
                    if(list_data.getTail() == NULL){
                        system("cls");
                        makeborder(); 
                        print_centered("Empty List",9);
                        gotoxy(2,19);
                        system("pause");
                    }
                    else {
                        system("cls");
                        makeborder(); 
                        print_centered("Enter the number of index which want to delete",9);
                        gotoxy(25,10);
                        int index;
                        std::cin >> index;
                        list_data.deleteI(index);
                    }
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    delete_flow = 5;
                    break;
                case 4:
                    if(list_data.getTail() == NULL){
                        system("cls");
                        makeborder(); 
                        print_centered("Empty List",9);
                        gotoxy(2,19);
                        system("pause");
                    }
                    else {
                        list_data.deleteAll();
                        system("cls");
                        makeborder(); 
                        print_centered("All Data has been deleted",9);
                        gotoxy(2,19);
                        system("pause");
                    }
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    delete_flow = 5;
                    break;
                default:
                    system("cls");
                    makeborder();
                        do{
                            std::string selection[5] = {"Delete in Beginning","Delete in Last","Delete at Index","Delete all Data","Back to Menu"};
                            /*Perulangan untuk menampilkan semua pilihan atau opsi*/
                            for(int i = 0; i < 5; i++){
                                (delete_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            /*Meminta input kontrol dari user*/
                            buffer = getch();
                            /*Fungsi yang membaca, mengatur, dan menjaga nilai flow agar tidak melebihi batas*/
                            inputCTRL(buffer,delete_flow,1,5);
                        }while(buffer != 13);
                    break;
                }
            }while(delete_flow != 5);
            /*Mereset nilai agar kembali ke menu utama*/
            flow = 0;
            color(7);
            gotoxy(1,29);
            break;
        /*case untuk masuk ke menu Shift */
        /*Shift mewakilkan angka 2*/
        case Shift:
            /*mereset nilai shift_flow ke 0 agar masuk ke case default*/
            shift_flow = 0;
            do{
                makeborder(); 
                switch (shift_flow)
                {
                case 1:
                    /*Menjalankan fungsi untuk menggeser nilai pada linked list ke kanan
                    index 0 menjadi 1, 2 jadi 3, 3 jadi 4, dst*/
                    list_data.shift_right();
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    shift_flow = 3;
                    break;
                case 2:
                    /*Menjalankan fungsi untuk menggeser nilai pada linked list ke kiri
                    index 4 jadi 3, 3 jadi 2, 2 jadi 1, 1 jadi 0, dan 0 jadi index terakhir*/
                    list_data.shift_left();
                    /*Mereset nilai agar kembali ke menu utama*/
                    flow = 0;
                    shift_flow = 3;
                    break;
                /*Sub menu pada switch Shift untuk meminta pilihan
                dari user*/
                default:
                    system("cls");
                    makeborder();
                        do{
                            std::string selection[3] = {"Shift Right","Shift Left","Back to Menu"};
                            /*Perulangan untuk menampilkan semua pilihan atau opsi*/
                            for(int i = 0; i < 3; i++){
                                (shift_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            /*Meminta input kontrol dari user*/
                            buffer = getch();
                            /*Fungsi yang membaca, mengatur, dan menjaga nilai flow agar tidak melebihi batas*/
                            inputCTRL(buffer,shift_flow,1,3);
                        }while(buffer != 13);
                    break;
                }
            }while(shift_flow != 3);
            /*Mereset nilai agar kembali ke menu utama*/
            flow = 0;
            color(7);
            gotoxy(1,29);
            break;
        /*Main menu pada switch utama untuk meminta pilihan dari user*/
        default:
            makeborder();
                do{
                    std::string selection[5] = {"Print All Data","Insert Data","Delete Data","Shift Data","Quit"};
                    /*Perulangan untuk menampilkan semua pilihan atau opsi*/
                    for(int i = 0; i < 5; i++){
                        (flow == i+1) ? color(3) : color(7);
                        print_centered(selection[i],i+9);
                    }
                    color(7);
                    gotoxy(2,19);
                    std::cout << "W : up and S : down";
                    /*Meminta input kontrol dari user*/
                    buffer = getch();
                    /*Fungsi yang membaca, mengatur, dan menjaga nilai flow agar tidak melebihi batas*/
                    inputCTRL(buffer,flow,1,5);
                }while(buffer != 13);
            break;
        }
    }while(flow != 5);
    gotoxy(0,21);
    return 0;
}

/*Fungsi  untuk mengatur posisi kursor*/
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*Fungsi untuk menampilkan border*/
void makeborder(){
    gotoxy(1,1);               std::cout << corner_LU;
    gotoxy(50,1);              std::cout << corner_RU;
    gotoxy(1,20);              std::cout << corner_LD; 
    gotoxy(50,20);             std::cout << corner_RD; 

    for(int i = 2; i < 50; i++){
        gotoxy(i,1);           std::cout << hori; 
        gotoxy(i,20);          std::cout << hori; 
    }

    for(int i = 2; i < 20; i++){
        gotoxy(1,i);           std::cout << verti;
        gotoxy(50,i);          std::cout << verti;
    }
}

/*Fungsi  untuk merubah warna*/
void color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

/*Fungsi untuk membaca, mengatur, dan menjaga input dari user agar tidak melebihi batas
Parameter pertama untuk varibel yang menerima input
Parameter kedua untuk varibel output atau variabel yang mengatur alur program
Parameter ketiga untuk batas minimum nilai dari flow atau variabel yang mengatur alur program
Parameter keempat untuk batas maksimum nilai dari flow atau variabel yang mengatur alur program*/
void inputCTRL(int temp, int &out, int min, int max){
	if((temp == 'w' or temp == 'W') and out > min){
		out--;
	}else if((temp == 's' or temp == 'S') and out < max){
		out++;
	}
}

/*Fungsi untuk mencetak string di tengah (alignment)*/
void print_centered(const std::string &s,int y) {
    int spaces = ((47 - s.length()) / 2);
    gotoxy(2,y);
    std::cout << std::setw(spaces) << std::setfill(' ') << "" << s << std::setw(47 - spaces - s.length()) << std::setfill(' ') << "" << std::endl;
}

/*Fungsi untuk membuat Node baru dengan yang nextnya mengarah pada dirinya sendiri*/
Node* Node::makeNew(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = temp;
    return temp;
}

/*Fungsi Getter untuk mendapatkan nilai dari tail
Yang dapat digunakan sebagai pengecakan linked list pada Main Function*/
Node* Node::getTail(){
    return tail;
}

/*Fungsi untuk menampilkan seluruh data dari linked list*/
void Node::printAll(){
    /*Pengecekan kondisi linked list
    jika kosong maka akan menampilkan empty list dan langsung keluar dari fungsi*/
    if(Node::tail == NULL){
        print_centered("Empty List",10);
        return;
    }
    /*Node sementara sebagai penunjuk list*/
    Node *temp = Node::tail->next;
    /*Variabel untuk mengatur posisi dari data list yang akan ditampilkan*/
    int x = 2, y = 2, count = 0;
    do{
        gotoxy(x,y);
        std::cout << count << " : " <<temp->data;
        gotoxy(x+9,y);
        std::cout << "|";
        temp = temp->next;
        x+=10;
        if(x >= 42){
            x =  2;
            y += 1;
        }
        count++;
    }while(temp != Node::tail->next);
    std::cout << '\n';
}

/*Fungsi untuk menambahkan data pada akhir linked list*/
void Node::addLast(int value){
    /*Membuat Node baru*/
    Node *newNode = makeNew(value);
    /*Pengecekan kondisi linked list
    jika kosong maka akan menjadikan data yang tebaru sebagai tail 
    dan langsung keluar dari fungsi*/
    if(Node::tail == NULL){
        Node::tail = newNode;
        return;
    }
    newNode->next = Node::tail->next;
    Node::tail->next = newNode;
    Node::tail = newNode;
}

/*Fungsi untuk menambahkan data pada awal linked list*/
void Node::addBegin(int value){
    /*Membuat node baru*/
    Node *newNode = makeNew(value);
    /*Pengecekan kondisi linked list
    jika kosong maka akan menjadikan data yang tebaru sebagai tail 
    dan langsung keluar dari fungsi*/
    if(Node::tail == NULL){
        Node::tail = newNode;
        return;
    }
    newNode->next = Node::tail->next;
    Node::tail->next = newNode;
}  

/*Fungsi untuk memasukkan data pada index yang ditentukan
Parameter pertama untuk menentukan posisi index*/
void Node::insert(int pos, int value){
    /*Pengecekan kondisi. Apabila pos 0 make nilai dimasukkan dengan menggunakan fungsi addBegin
    dan langsung keluar dari fungsi*/
    if(pos == 0){
        addBegin(value);
        return;
    }
    /*Membuat node baru*/
    Node *newNode = makeNew(value);
    /*Membuat variabel temp untuk menunjuk ke index yang diinginkan*/
    Node *temp = Node::tail->next;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
        /*Pengecekan kondisi apakah index sudah mencapai akhir dari linked list
        Jika kondisi benar, maka berarti nilai pos yang dimasukkan lebih besar
        dari jumlah data yang ada pada linked list*/
        if(temp == Node::tail){
            gotoxy(2,10);
            system("cls");
            makeborder();  
            std::string text_temp = "Adding data " + std::to_string(value) + " in index " + std::to_string(pos) + " failed";
            print_centered(text_temp,9);
            gotoxy(2,19);
            system("pause");
            return;
        }
    }
    /*Assigment untuk meletakkan nilai dari newNode*/
    newNode->next = temp->next;
    temp->next = newNode;
}
/*Menjalankan fungsi untuk menggeser nilai pada linked list ke kanan
index 0 menjadi 1, 2 jadi 3, 3 jadi 4, dst*/
void Node::shift_right(){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(tail == NULL){
        system("cls");
        makeborder();
        print_centered("Empty List",9);
        gotoxy(2,19);
        
        system("pause");
        return;
    }
    Node *temp = Node::tail->next;
    while(temp->next != Node::tail){
        temp = temp->next;
    }
    Node::tail = temp;
}

/* Fungsi untuk menggeser nilai pada linked list ke kiri
index 4 jadi 3, 3 jadi 2, 2 jadi 1, 1 jadi 0, dan 0 jadi index terakhir*/ 
void Node::shift_left(){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(tail == NULL){
        system("cls");
        makeborder();
        print_centered("Empty List",9);
        gotoxy(2,19);
        system("pause");
        return;
    }
    Node::tail = Node::tail->next;
}

void Node::deleteLast(){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(Node::tail == NULL){
        system("cls");
        makeborder();
        print_centered("Empty List",9);
        gotoxy(2,19);
        system("pause");
        return;
    }
    
    Node *current = Node::tail->next;
    Node *prev = Node::tail;
    while (current->next != Node::tail->next) {
        prev = current;
        current = current->next;
    }
    
    if (prev == Node::tail) {
        delete Node::tail;
        Node::tail = NULL;
    }
    else {
        prev->next = Node::tail->next;
        Node::tail = prev;
        delete current;
    }
}

void Node::deleteBeg(){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(Node::tail == NULL){
        system("cls");
        makeborder();
        gotoxy(2,19);
        system("pause");
        print_centered("Empty List",9);
        return;
    }
    Node* delObj = Node::tail->next;
    Node::tail->next = Node::tail->next->next;
    delete delObj;
    tail = NULL;
}

void Node::deleteI(int pos){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(Node::tail == NULL)
    {
        system("cls");
        makeborder();
        print_centered("Empty List",9);
        gotoxy(2,19);
        system("pause");
        return;
    }
    /*Jika pos sama dengan 0 maka akan menghapus nilai dengan fungsi deleteBeg*/
    else if (pos == 0 or Node::tail->next == Node::tail) {
        Node::deleteBeg();
        return;
    }
    else {
        /*Menambahkan 1 agar berada pada awal list*/
        pos++;
        Node* del = Node::tail->next;
        Node* temp = Node::tail;
        /*Perulangan untuk menuju ke index yang diinginkan*/
        for (int i = 0; i < pos - 1; i++) {
            temp = del;
            del = del->next;
            /*Pengecekan kondisi apakah data berada pada linked list*/
            if (del->next == Node::tail) {
                system("cls");
                makeborder();
                print_centered("Index not found", 9);
                gotoxy(2, 19);
                system("pause");
                return;
            }
        }
        // Update the next pointer of the node before the position to be deleted to skip the node to be deleted
        temp->next = del->next;
        // Delete the node at the specified position
        delete del;
    }
}

void Node::deleteAll(){
    /*Pengecekan kondisi linked list jika kosong maka akan langsung keluar dari fungsi*/
    if(Node::tail == NULL)
    {
        return;
    }
    Node *temp = Node::tail->next;
    Node::tail->next = NULL;
    while (temp != NULL) {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;

        if (temp == Node::tail->next) {
            Node::tail = NULL;
            break;
        }
    }
    /*Membuat tail menjadi  NULL agar menandakan linked list sudah kosong*/
    Node::tail = NULL;
}

/*Memanggil fungsi deleteAll ketika linked list dihapus agar mencegah memory leak*/
Node::~Node(){
    deleteAll();
}