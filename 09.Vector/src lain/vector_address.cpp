#include <vector>
#include <iostream>
#include <windows.h>

int main(){
    std::vector<short> storage(4);
    std::cout << "vector capacity : " << storage.capacity() << std::endl;
    std::cout << "Address of vector : " << &storage << std::endl;
    
    for(int i = 0, j = storage.capacity(); i < j; i++){
        storage[i] = i + 1;
        std::cout << "Address at index\t["<< i << "] : " << &storage[i] << std::endl;
        std::cout << "value at index \t\t["<< i << "] : " << storage[i] << std::endl;
    }
    
    storage.push_back(3);
    std::cout << "After push back 1 element" << std::endl;
    std::cout << "vector capacity : " << storage.capacity() << std::endl;
    std::cout << "Address of vector : " << &storage << std::endl;

    for(int i = 0, j = storage.capacity(); i < j; i++){
        std::cout << "Address at index ["<< i << "] : " << &storage[i] << std::endl;
    }
    
    storage.reserve(9);
    
    std::cout << "After reserve(9)" << std::endl;
    std::cout << "vector capacity : " << storage.capacity() << std::endl;
    std::cout << "Address of vector : " << &storage << std::endl;

    for(int i = 0, j = storage.capacity(); i < j; i++){
        std::cout << "Address at index ["<< i << "] : " << &storage[i] << std::endl;
    }

    /*  The conclusion is if the capacity is full and we do push back function the vector will make a copy
    from the last vector in another place in memory and delete the old vector. It will take much time.

        In the third part of this code is the reserve function will make a copy of the last vector to a new on in
    another free space in memory. Because the first space has deleted and be free, the reserve function makes
    the new vector in the first place which was deleted in second part by push back function.
    */
    return 0;
}