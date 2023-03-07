#include <iostream>
class First{
    public:
        First(){
            std::cout << "constructor from class first" << std::endl;
        }
        ~First(){
            std::cout << "destructor from class First" << std::endl;
        }
};

class Second{
    private:
        First* obj;
    public:
        Second(){
            obj = new First;
            std::cout << "Constructor from class second" << std::endl;
        }
        ~Second(){
            delete obj;
            std::cout << "Destructor from class Second" << std::endl;
        }
};

int main(){
    {
        Second obj_in_main;
        std::cout << "di dalam scope" << std::endl;
    }
        std::cout << "di luar scope" << std::endl;
    return 0;
}