#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a = {1,3,5};
    for(auto f : a)
        cout << f ; cout << endl;
    a.at(0) = 2 ;
    for(auto f : a)
        cout << f ; cout << endl;
    // kesimpulannya adalah nilai dari vector pada index tertentu pada suatu vectore bisa di ubah
    // std::vector<int>::iterator it = a.begin();
    a.erase(a.begin() + 4);
    for(auto f : a)
        cout << f ; cout << endl;
}