#include <iostream>
#include <cmath>


int main() {

  int num;
  std::cout << "insert number: ";
  std::cin >> num;

  bool* primes{new bool[num+1]};
  std::fill(primes, primes + (num+1)*(sizeof(bool)), true);
  

  for(int i{2}; i<=std::sqrt(num); ++i) {
    if (primes[i]) {
      for(int j{i*i}; j<=num; j=j+i)
	primes[j] = false;
    }
  }

  for(int i{2}; i<=num; ++i) {
    if (primes[i])
      std::cout << i << "\n";
  }
  
  return 0;

}
