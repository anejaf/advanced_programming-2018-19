#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
Compute median of an array.
@param vec, std::vector of doubles.
*/
double median(std::vector<double>& vec) {
  std::sort(vec.begin(), vec.end());
  int mid = int(vec.size() / 2);
  if (vec.size() % 2 == 1)
    return vec[mid];
  return (vec[mid] + vec[mid-1]) / 2;
}

/**
Compute mean of an array.
@param vec, std::vector of doubles.
 */
double mean(const std::vector<double>& vec) {
  double sum{0};
  for (auto i=0llu; i<vec.size(); i++)
    sum += vec[i];
  return sum / vec.size();
}


void store_vals(std::vector<double>& vec, std::istream &stream) {
  double next;
  while (stream >> next)
    vec.push_back(next);
}


int main(int argc, char** argv) {

  std::ifstream f;
  if (argc > 1)
    f.open(argv[1]);
  else
    f.open("temperatures.txt");

  std::vector<double> temps;
  store_vals(temps, f);
  f.close();
  
  std::cout << mean(temps) << std::endl;
  std::cout << median(temps) << std::endl;
  
  return 0;

}
