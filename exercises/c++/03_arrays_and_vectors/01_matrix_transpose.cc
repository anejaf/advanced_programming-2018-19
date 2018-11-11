#include <iostream>
#include <array>
#include <iomanip>

/**
Matrix transpose function.
@param matrix, standard array of doubles of size N,
               where N is the total size of the matrix
@param rows, number of rows of the matrix
@param cols, number of columns of the matrix
 */
template<std::size_t N>
void transpose(std::array<double, N>& matrix, const int rows, const int cols) {
  std::array<double, N> mat_t;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat_t[j * rows + i] = matrix[i * cols + j];
    }
  }
  matrix = mat_t;
}

/**
Print matrix function.
@param matrix, standard array of doubles of size N,
               where N is the total size of the matrix
@param cols, number of columns of the matrix
 */
template<std::size_t N>
void print_matrix(std::array<double, N>& matrix, int cols) {
  int i{0};
  for (const auto el : matrix) {
    std::cout << std::setw(3) << el << " ";
    if (i % cols == cols - 1)
      std::cout << std::endl;
    i = i + 1;
  }
  std::cout << std::endl;
}


int main() {

  std::array<double, 12> mat{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  print_matrix(mat, 4);
  
  transpose(mat, 3, 4);
  print_matrix(mat, 3);

  return 0;
  
}
