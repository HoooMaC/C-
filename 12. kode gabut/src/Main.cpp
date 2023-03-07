#include <iostream>
int func(int n);
int main(){
    int jml = 0, counter = 5;
    do{
        counter++;
        if(counter%2 == 0){
            jml += counter;
        }
        else {
            jml -= counter;
        }
        std::cout << "counter : " << counter << std::endl;
        std::cout << "jml : " << jml << std::endl;
    } while(counter < 10);
    std::cout << " jml akhir :" << jml << std::endl;
    int sum = 0;
    for(int i = 0, j = 0; i < 5 & j < 5; ++i, j = i + 1){
        
        sum+=i;
        std::cout << " i : " << i << std::endl;
        std::cout << "sum : " << sum << std::endl;
    }

    for(int x = 0; x < 10; x++)
        for(x+=1; x <=5; ++x)
        std::cout << ++x << ' ';
    std::cout << "nilai " << func(5) << std::endl;
}

int func(int n){
    if(n == 0) return 1;
    else if(n % 2 == 0) return n*func(n-1);
    else return 1+func(n-1);
}