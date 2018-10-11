#include <iostream>
#include <string>


int get_int() {
  int i;
  while(!(std::cin >> i) || std::cin.get() != '\n') {
    std::cin.clear();
    std::cin.ignore();
  }
  return i;
}


double get_double() {
  double i;
  while(!(std::cin >> i) || std::cin.get() != '\n') {
    std::cin.clear();
    std::cin.ignore();
  }
  return i;
}


int main() {

  int i = get_int();
  // double i = get_double();

  std::cout << i << "\n";
  
  return 0;

}
