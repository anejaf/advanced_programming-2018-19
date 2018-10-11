#include<iostream>


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

  int primes[50];
  
  int j{0};
  for(int i{0}; i<100; ++i){
    if(is_prime(i)) {
      primes[j] = i;
      j = j+1;
    }
  }

  for(int i{0}; i<j; ++i) {
    std::cout << primes[i] << " ";
  }

  std::cout << std::endl;
  
  return 0;
  
}
