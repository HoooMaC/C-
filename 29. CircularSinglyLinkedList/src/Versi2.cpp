#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#define corner_RU '\xBB'
#define corner_RD '\xBC'
#define corner_LU '\xC9'
#define corner_LD '\xC8'
#define verti '\xBA'
#define hori  '\xCD'

void gotoxy(int x, int y);
void makeborder();
void color(int color);
void inputCTRL(int temp, int &out, int min, int max);
void print_centered(const std::string &s,int y);

class Node{
private:
    Node *tail = NULL;
public:
    int data;
    Node *next;
    Node* makeNew(int value);
    void printAll();
    void addLast(int value);
    void addBegin(int value);
    void insert(int pos, int value);
    void shift_right();
    void shift_left();
    void deleteLast();
    void deleteBeg();
    void deleteI(unsigned int pos);
    void deleteAll();
    ~Node();
};

enum menu{Print=1,Insert,Delete,Shift,Quit};
int main(){
    int temp = 0;
    Node list_data;
    int option = 0;
    int insert_flow = 0, delete_flow = 0,shift_flow = 0;
    system("cls");
    makeborder();
    print_centered("Name : Gunawan",9);
    print_centered("NIM : 225150307111042",10);
    gotoxy(2,19);
    system("pause");
    do{
        
        system("cls");
        switch (option)
        {
        case Print:
            makeborder();
            list_data.printAll();
            gotoxy(2,19);
            system("pause");
            option = 0;
            break;
        case Insert:
            insert_flow = 0;
            system("cls");
            do{
                int value;
                makeborder(); 
                switch (insert_flow)
                {
                case 1:
                    system("cls");
                    makeborder(); 
                    print_centered("Enter the value",10);
                    gotoxy(25,11);
                    std::cin >> value;
                    list_data.addBegin(value);
                    option = 0;
                    insert_flow = 4;
                    break;
                case 2:
                    system("cls");
                    makeborder(); 
                    print_centered("Enter the value",10);
                    gotoxy(25,11);
                    std::cin >> value;
                    list_data.addLast(value);
                    option = 0;
                    insert_flow = 4;
                    break;
                case 3:
                    system("cls");
                    makeborder(); 
                    print_centered("Enter the number of index which want to insert",8);
                    gotoxy(25,9);
                    int index;
                    std::cin >> index;
                    print_centered("Enter the value",10);
                    gotoxy(25,11);
                    int number;
                    std::cin >> number;
                    list_data.insert(index,number);
                    option = 0;
                    insert_flow = 4;
                    break;
                default:
                    makeborder();
                        do{
                            std::string selection[4] = {"Insert in Beginning","Insert in Last","Insert in Index","Back to Menu"};
                            for(int i = 0; i < 4; i++){
                                (insert_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            temp = getch();
                            inputCTRL(temp,insert_flow,1,4);
                        }while(temp != 13);
                    break;
                }
            }while(insert_flow != 4);
            option = 0;
            color(7);
            gotoxy(1,29);
            break;
        case Delete:
            delete_flow = 0;
            system("cls");
            do{
                makeborder(); 
                switch (delete_flow)
                {
                case 1:
                    list_data.deleteBeg();
                    option = 0;
                    delete_flow = 4;
                    break;
                case 2:
                    list_data.deleteLast();
                    option = 0;
                    delete_flow = 4;
                    break;
                case 3:
                    system("cls");
                    makeborder(); 
                    print_centered("Enter the number of index which want to delete",9);
                    gotoxy(25,10);
                    int index;
                    std::cin >> index;
                    list_data.deleteI(index);
                    option = 0;
                    delete_flow = 4;
                    break;
                default:
                    system("cls");
                    makeborder();
                        do{
                            std::string selection[4] = {"Delete in Beginning","Delete in Last","Delete in Index","Back to Menu"};
                            for(int i = 0; i < 4; i++){
                                (delete_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            temp = getch();
                            inputCTRL(temp,delete_flow,1,4);
                        }while(temp != 13);
                    break;
                }
            }while(delete_flow != 4);
            option = 0;
            color(7);
            gotoxy(1,29);
            break;
        case Shift:
            shift_flow = 0;
            do{
                makeborder(); 
                switch (shift_flow)
                {
                case 1:
                    list_data.shift_right();
                    option = 0;
                    shift_flow = 4;
                    break;
                case 2:
                    list_data.shift_right();
                    option = 0;
                    shift_flow = 4;
                    break;
                default:
                    system("cls");
                    makeborder();
                        do{
                            std::string selection[3] = {"Shift Right","Shift Left","Back to Menu"};
                            for(int i = 0; i < 3; i++){
                                (shift_flow == i+1) ? color(3) : color(7);
                                print_centered(selection[i],i+9);
                            }
                            gotoxy(2,19);
                            temp = getch();
                            inputCTRL(temp,shift_flow,1,3);
                        }while(temp != 13);
                    break;
                }
            }while(shift_flow != 3);
            option = 0;
            color(7);
            gotoxy(1,29);
            break;
        default:
            makeborder();
                do{
                    std::string selection[5] = {"Print All Data","Insert Data","Delete Data","Shift Data","Quit"};
                    for(int i = 0; i < 5; i++){
                        (option == i+1) ? color(3) : color(7);
                        print_centered(selection[i],i+9);
                    }
                    gotoxy(2,19);
                    temp = getch();
                    // std::cout << temp;
                    inputCTRL(temp,option,1,5);
                }while(temp != 13);
            break;
        }
    }while(option != 5);
    return 0;
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

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

void color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void inputCTRL(int temp, int &out, int min, int max){
	if((temp == 'w' or temp == 'W') and out > min){
		out--;
	}else if((temp == 's' or temp == 'S') and out < max){
		out++;
	}
}

void print_centered(const std::string &s,int y) {
    int spaces = ((47 - s.length()) / 2);
    gotoxy(2,y);
    std::cout << std::setw(spaces) << std::setfill(' ') << "" << s << std::setw(47 - spaces - s.length()) << std::setfill(' ') << "" << std::endl;
}

Node* Node::makeNew(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = temp;
    return temp;
}

void Node::printAll(){
    if(Node::tail == NULL){
        print_centered("Empty List",10);
        return;
    }
    Node *temp = Node::tail->next;
    int x = 2, y = 2;
    do{
        gotoxy(x,y);
        std::cout << temp->data << ' ';
        temp = temp->next;
        x+=5;
        if(x > 45){
            x =  2;
            y += 1;
        }
    }while(temp != Node::tail->next);
    std::cout << '\n';
}

void Node::addLast(int value){
    Node *newP = makeNew(value);
    if(Node::tail == NULL){
        Node::tail = newP;
        return;
    }
    newP->next = Node::tail->next;
    Node::tail->next = newP;
    Node::tail = newP;
}

void Node::addBegin(int value){
    Node *newP = makeNew(value);
    if(Node::tail == NULL){
        Node::tail = newP;
        return;
    }
    newP->next = Node::tail->next;
    Node::tail->next = newP;
}  

void Node::insert(int pos, int value){
    if(Node::tail == NULL){
        system("cls");
        makeborder();
        print_centered("List is Empty",10);
        print_centered("Entering number to first index",11);
        Node::addBegin(value);
        gotoxy(2,19);
        system("pause");
        return;
    }
    if(pos == 0){
        addBegin(value);
        return;
    }
    Node *newP = makeNew(value);
    Node *temp = Node::tail->next;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
        if(temp == Node::tail){
            gotoxy(2,10);
            std::cout << "Adding data " << value << " in index " << pos << " failed\n";
            gotoxy(2,11);
            system("pause");
            return;
        }
    }
    newP->next = temp->next;
    temp->next = newP;
}

void Node::shift_right(){
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

void Node::shift_left(){
    if(tail == NULL){
        system("cls");
        makeborder();
        print_centered("Empty List",9);
        gotoxy(2,19);
        system("pause");
        return;
    }
    Node *current = Node::tail->next;
    while(current->next != Node::tail){
        current = current->next;
    }
    Node::tail = current;
}

void Node::deleteLast(){
    if(Node::tail == NULL){
        std::cout << "Empty List\n";
        return;
    }
    
    Node *current = Node::tail->next;
    Node *prev = Node::tail;
    while(current != Node::tail){
        prev = current;
        current = current->next;
    }
    
    if(prev == Node::tail){
        Node::tail = NULL;
    }
    else {
        prev->next = Node::tail->next;
        Node::tail = prev;
    }
    delete current;
}

void Node::deleteBeg(){
    if(Node::tail == NULL){
        std::cout << "Empty List\n";
        return;
    }
    Node* delObj = Node::tail->next;
    Node::tail->next = Node::tail->next->next;
    delete delObj;
    Node::printAll();
}

void Node::deleteI(unsigned int pos){
    if(Node::tail == NULL)
    {
        std::cout << "Empty List\n";
        return;
    }
    if(pos == 0){
        Node::deleteBeg();
    }
    else{
        Node *del = Node::tail->next;
        Node *temp = Node::tail;
        for(int i = 0; i < pos; i++){
            temp = del;
            del = del->next;
            std::cout << i << ". ";
            std::cout << "data :" << del->data << ' '
                      << "next :" << del->next->data << '\n';
            if(del == Node::tail){
                std::cout << "Data not found\n";
                return;
            }
        }
        temp->next = del->next;
        delete del;
    }
}

void Node::deleteAll(){
    if(Node::tail == NULL)
    {
        // std::cout << "Empty List\n";
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
    Node::tail = NULL;
    std::cout << "All item has been deleted\n";
}

Node::~Node(){
    deleteAll();
}