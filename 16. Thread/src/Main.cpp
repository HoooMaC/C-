#include <iostream>
#include <thread>
static bool key = false;
class MyClass {
public:
  void run() {
    // Do something in a loop
    while (!key) {
      std::cout << "Running in a thread" << std::endl;
    }
  }
};

int main() {
  MyClass obj;
  std::thread t(&MyClass::run, &obj); // Create a thread and run the run() function in the obj object

  // Do something else in the main thread
  // for (int i = 0; i < 10; i++) {
  //   std::cout << "Running in the main thread" << std::endl;
  // }
  std::cin.get();
  key = true;
  t.join(); // Wait for the thread to finish
  return 0;
}
