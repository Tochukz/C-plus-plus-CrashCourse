#include <cstdio>
#include <array>

template<typename T>
T mean(T* numbers, size_t length) {
  T result {};
  for(size_t i {}; i < length; i++) {
    result += numbers[i];
  }

  // T mean = static_cast<T>(result/length);
  // printf("Result= %d | %f, length = %d , mean %d | %f\n", result, result, length, mean, mean);
  // return mean;
  return result/length;
}


int main() {
  double scores[] { 78.5, 69.2, 87.4, 64.1, 77.9};
  double meanScore = mean<double>(scores, std::size(scores));
  printf("Mean Score = %f \n", meanScore); // Mean Score = 75.420000

  int marks[] {78, 69, 87, 64, 77};
  int meanMark = mean<int>(marks, std::size(marks));
  printf("Mean Mark = %d \n", meanMark); // Mean Mark = 75

  float wins[] {78.0f, 69.5f, 87.5f, 64.0f, 77.5f};
  float meanWin = mean(wins, std::size(wins)); // (1)
  printf("Mean Win = %f \n", meanWin); // Mean Win = 75.300003
}

/**
  1) You may omit template parameter when you instantiate a template function.
  In that case the compiler will use template type deduction to determine the type
  But if a template function’s return type is a template argument, you must specify template arguments explicitly

  NB: std::size() is only available in <array> header of C++17
*/
