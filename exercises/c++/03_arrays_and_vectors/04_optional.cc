#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <chrono>
#include <istream>
#include <fstream>

using namespace std::chrono;

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
Frequency count of a string vector using std::map.
Returns a std::map of string frequency.
@param vec, standard vector of strings.
 */
std::map<std::string, int> frequency(const std::vector<std::string>& vec) {
  std::map<std::string, int> v_count;
  for (const auto& v : vec)
    ++v_count[v];
  return v_count;
}

/**
Frequency count of a string vector using std::unordered_map.
Returns a std::unordered_map of string frequency.
@param vec, standard vector of strings.
 */
std::unordered_map<std::string, int> frequency_unord(const std::vector<std::string>& vec) {
  std::unordered_map<std::string, int> v_count;
  for (const auto&v : vec)
    ++v_count[v];
  return v_count;
}


int main(int argc, char** argv) {

  std::vector<std::string> words;
  
  if (argc > 1) {
    std::ifstream f;
    f.open(argv[1]);
    store_strings(words, 1, f);
    f.close();
  }
  else
    store_strings(words, 1, std::cin);

  // time word frequency counting
  std::cout << "Using std::map.." << std::endl;
  auto start = steady_clock::now();
  auto word_count = frequency(words);
  auto end = steady_clock::now();
  std::cout <<
    duration <double, std::nano> (end-start).count() << " ns" << std::endl;

  std::cout << "Using std::unordered_map.." << std::endl;
  start = steady_clock::now();
  auto word_count2 = frequency_unord(words);
  end = steady_clock::now();
  std::cout <<
    duration <double, std::nano> (end-start).count() << " ns" << std::endl;

  // print result
  for (const auto& word : word_count)
    std::cout << word.first << " " << word.second << std::endl;
  
  
  return 0;
  
}
