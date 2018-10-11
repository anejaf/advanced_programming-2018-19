#include <iostream>
#include<vector>


int is_prime(int num) {

  if (num <=1)
    return 0;

  else if (num <= 3)
    return 1;

  else if (num % 2 == 0 || num % 3 == 0)
    return 0;

  for(int i{5}; i*i <= num; i=i+6) {
    if (num % i == 0 || num % (i+2) == 0)
      return 0;
  }

  return 1;
  
}


int main() {

  std::vector<int> primes = {};

  for(int i{0}; i<100; ++i) {
    if (is_prime(i))
      primes.push_back(i);
  }

  for(int num : primes) {
    std::cout << num << " ";
  }

  std::cout << std::endl;

  return 0;

}
