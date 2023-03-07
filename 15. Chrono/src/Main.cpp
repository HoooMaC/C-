#include <chrono>
#include <iostream>

int main() {
    // Start the timer
    auto start = std::chrono::steady_clock::now();

    // Do some work here
    // ...
    for(int i = 0; i < 1000;i++)
        std::cout << "Hello world";
    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Calculate the elapsed time
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Elapsed time: " << elapsed_time << " microseconds" << std::endl;

    return 0;
}
