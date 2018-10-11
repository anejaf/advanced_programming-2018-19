#include <iostream>
#include <string>


int decide_line(int pos, int len_curr, int len) {

  if (len_curr + pos + 1 > len + 1) {
    std::cout << "\n";
    return pos + 1;
  }
  
  return len_curr + pos + 1;
}


int main() {

  std::cout << "Input desired number of characters in a line: ";

  int len;
  std::cin >> len;
  
  std::string line;

  while(std::getline(std::cin, line)) {

    std::size_t pos{0};
    int len_current{0};

    while((pos = line.find(" ")) < std::string::npos) {

      std::string word = line.substr(0, pos);

      len_current = decide_line(pos, len_current, len);
      
      std::cout << word << " ";
      line.erase(0, pos+1);
    }

    len_current = decide_line(line.length(), len_current, len);
    std::cout << line << "\n";    

  }

  return 0;
  
}
