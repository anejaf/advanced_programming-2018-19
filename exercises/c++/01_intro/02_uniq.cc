#include <iostream>
#include <string>


int main() {

  std::string prev_line;

  if(!(std::getline(std::cin, prev_line))) {
    return 0;
  }
  
  unsigned int i{1};

  std::string line;
  
  while(std::getline(std::cin, line)) {
    if (prev_line == line) {
      i = i + 1;
      continue;
    }
    std::cout << i << " " << prev_line << "\n"; 
    i = 1;
    prev_line = line;
  }

  std::cout << i << " " << prev_line << "\n";
  
  return 0;

}
