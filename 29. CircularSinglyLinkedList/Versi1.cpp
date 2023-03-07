#include <iostream>

struct NODE;

NODE* makeNew(int value);
NODE* tail = NULL;
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

int main(){
    addBegin(32);
    addBegin(43);
    addBegin(54);
    addBegin(43);
    addBegin(23);
    insert(10,78);
    printAll();
    deleteI(10);
    return 0;
}

struct NODE{
    NODE* next;
    int data;
};

NODE* makeNew(int value){
    NODE *temp = new NODE;
    temp->data = value;
    temp->next = temp;
    return temp;
}

void printAll(){
    if(tail == NULL){
        std::cout << "Empty List\n";
        return;
    }
    NODE *temp = tail->next;
    do{
        std::cout << temp->data << ' ';
        temp = temp->next;
    }while(temp != tail->next);
    std::cout << '\n';
}

void addLast(int value){
    NODE *newP = makeNew(value);
    if(tail == NULL){
        tail = newP;
        return;
    }
    newP->next = tail->next;
    tail->next = newP;
    tail = newP;
}

void addBegin(int value){
    NODE *newP = makeNew(value);
    if(tail == NULL){
        tail = newP;
        return;
    }
    newP->next = tail->next;
    tail->next = newP;
}  

void insert(int pos, int value){
    if(pos == 0){
        addBegin(value);
        return;
    }
    NODE *newP = makeNew(value);
    NODE *temp = tail->next;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
        if(temp == tail){
            std::cout << "Data Not Found\n";
            return;
        }
    }
    newP->next = temp->next;
    temp->next = newP;
    printAll();
}

void shift_right(){
    tail = tail->next;
}

void shift_left(){
    NODE *current = tail->next;
    while(current->next != tail){
        current = current->next;
    }
    tail = current;
}

void deleteLast(){
    if(tail == NULL){
        std::cout << "Empty List\n";
        return;
    }
    
    NODE *current = tail->next;
    NODE *prev = tail;
    while(current != tail){
        prev = current;
        current = current->next;
    }
    
    if(prev == tail){
        tail = NULL;
    }
    else {
        prev->next = tail->next;
        tail = prev;
    }
    delete current;
}

void deleteBeg(){
    if(tail == NULL){
        std::cout << "Empty List\n";
        return;
    }
    NODE* delObj = tail->next;
    tail->next = tail->next->next;
    delete delObj;
    printAll();
}

void deleteI(unsigned int pos){
    if(tail == NULL)
    {
        std::cout << "Empty List\n";
        return;
    }
    if(pos == 0){
        deleteBeg();
    }
    else{
        NODE *del = tail->next;
        NODE *temp = tail;
        for(int i = 0; i < pos; i++){
            temp = del;
            del = del->next;
            std::cout << i << ". ";
            std::cout << "data :" << del->data << ' '
                      << "next :" << del->next->data << '\n';
            if(del == tail){
                std::cout << "Data not found\n";
                return;
            }
        }
        temp->next = del->next;
        delete del;
    }
}

void deleteAll(){
    if(tail == NULL)
    {
        std::cout << "Empty List\n";
        return;
    }
    NODE * temp = tail->next;
    tail->next = NULL;
    while (temp != NULL) {
        NODE *nextNode = temp->next;
        delete temp;
        temp = nextNode;

        if (temp == tail->next) {
            tail = NULL;
            break;
        }
    }
    tail = NULL;
}
