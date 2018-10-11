#include <iostream>

int sum_1(int a) {
  return a + 1;
}


int main() {

  // typo in function name
  std::c0ut << "Hello, world!\n";

  // typo in variable name
  int a{0};
  std::c0ut << aa;

  // forget to put ;
  // std::cout << "Hello, world!\n""

  // declare a variable with illegal name
  int double {0};

  // pass wrong type of argument to function
  double b{0.5};
  std::cout << sum_1(b);

  return 0;
}
