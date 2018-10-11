#include <iostream>


template <typename T>
T* alloc_array(std::size_t len) {
  return new T[len];
}


template <typename T>
void print_reversed(T* arr, std::size_t len) {
  for (std::size_t i{len}; i>0; i--)
    std::cout << arr[i-1] << " ";
  std:: cout << std::endl;
}


int main() {

  std::size_t len;
  std::cin >> len;

  // double* arr{alloc_array<double>(len)};
  int* arr{alloc_array<int>(len)};

  for(std::size_t i{0}; i<len; i++)
    std::cin >> arr[i];
  
  print_reversed(arr, len);
  
  delete[] arr;
  
  return 0;

}
