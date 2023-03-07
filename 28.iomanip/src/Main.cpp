#include <iostream>
#include <iomanip>
#include <string>

void print_centered(const std::string &s, int width) {
  int spaces = (width - s.length()) / 2;
  std::cout << std::setfill(' ') << std::setw(spaces + s.length()) << std::left << s << std::endl;
}

int main() {
  std::string s = "center";
  print_centered(s, 20);
  return 0;
}
