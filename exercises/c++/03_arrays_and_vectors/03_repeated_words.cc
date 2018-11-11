#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <istream>
#include <fstream>

/**
Function for cleaning a string.
Function cleans a string of special characters 
('.', ',', '?', '!', '"') and numbers and spaces.
@param str, standard string.
*/
void clean_string(std::string& str) {
  str.erase(std::remove_if(str.begin(), 
                           str.end(),
                           [](char c){
			     return
			       isspace(c) || !isalpha(c) || c == '.' ||
			       c == '!' || c == ',' || c == '\"' || c == '?';
			   }),
	    str.end());
}

/**
Function for storing strings in a standard vector.
@param vec, standard vector to store the strings in.
@param clean, boolean on whether or not to clean the strings.
@param stream, open stream to read the strings from.
 */
void store_strings(std::vector<std::string>& vec, int clean, std::istream& stream) {
  std::string next;
  while (stream >> next) {
    if (clean == 1)
      clean_string(next);
    vec.push_back(next);
  }
}


/**
Function to avoid repeated words manually through a loop.
Function prints each word without repetition in sorted order.
@param vec, vector of strings.
 */
void avoid_repeat_manual(std::vector<std::string>& vec) {
  std::sort(vec.begin(), vec.end());
  std::string prev = vec[0];
  std::cout << prev << " ";
  for (auto i=1u; i<vec.size(); i++) {
    if (!prev.compare(vec[i]))
      continue;
    std::cout << vec[i] << " ";
    prev = vec[i];
  }
  std::cout << std::endl;
}


/**
Function to avoid repeated words using a built-in unique function.
Function prints each word without repetition in sorted order.
@param vec, vector of strings
 */
void avoid_repeat(std::vector<std::string>& vec) {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end() ), vec.end());
  for (const auto&v : vec)
    std::cout << v << " ";
  std::cout << std::endl;
}


int main(int argc, char** argv) {

  std::vector<std::string> vec;
  
  if (argc > 1) {
    std::ifstream f;
    f.open(argv[1]);
    store_strings(vec, 1, f);
    f.close();
  }
  else
    store_strings(vec, 1, std::cin);

  // avoid_repeat_manual(vec);
  avoid_repeat(vec);
  
  return 0;
  
}
