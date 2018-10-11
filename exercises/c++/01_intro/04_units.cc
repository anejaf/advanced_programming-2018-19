#include <iostream>
#include <string>


double inch_to_m(double inch) {

  return 0.0254 * inch;

}


int main() {

  std::string s;
  double d;

  std::cin >> d >> s;

  if (s != "inch")
    std::cout << "Sorry, this type of conversion is not supported.\n";

  else
    std::cout << inch_to_m(d) << " m\n";
  
  return 0;

}
