#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
  vector<int> numbers(100);
  for (int i = 0; i < 100; i++) {
    numbers[i] = i + 1;
  }

  srand(time(0));
  random_shuffle(numbers.begin(), numbers.end());

  for (int i = 0; i < 100; i++) {
    cout << numbers[i] << endl;
  }

  return 0;
}
