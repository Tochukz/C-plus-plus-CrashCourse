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
  double meanScore = mean<double>(scores, sizeof(scores)/sizeof(double));
  printf("Mean Score = %f \n", meanScore); // Mean Score = 75.420000

  int marks[] {78, 69, 87, 64, 77};
  int meanMark = mean<int>(marks, sizeof(marks)/sizeof(int));
  printf("Mean Mark = %d \n", meanMark); // Mean Mark = 75

  float wins[] {78.0f, 69.5f, 87.5f, 64.0f, 77.5f};
  float meanWin = mean(wins, sizeof(wins)/sizeof(float)); // (1)
  printf("Mean Win = %f \n", meanWin); // Mean Win = 75.300003

  // Using mean template with array of non-avaerable elements
  auto n1 = 0.1;
  auto n2 = 5.1;
  auto n3 = 3.5;
  const double* nPoiners[] {&n1, &n2, &n3};
  // mean(nPoiners, sizeof(nPoiners)/sizeof(&n1)); // error (2)
}

/**
  1) You may omit template parameter when you instantiate a template function.
  In that case the compiler will use template type deduction to determine the type
  But if a template functions return type is a template argument, you must specify template arguments explicitly

  2) Compilation Error:
  template-func.cpp: In instantiation of 'T mean(T*, size_t) [with T = const double*; size_t = unsigned int]':
  template-func.cpp:36:46:   required from here
  template-func.cpp:8:12: error: invalid operands of types 'const double*' and 'const double*' to binary 'operator+'
      result += numbers[i];
      ~~~~~~~^~~~~~~~~~~
  template-func.cpp:8:12: error:   in evaluation of 'operator+=(const double*, const double*)'
  template-func.cpp:14:16: error: invalid operands of types 'const double*' and 'size_t' {aka 'unsigned int'} to binary 'operator/'
    return result/length;

 Using concept provided a far more illuminating error message. See the example at ../concepts/averagable-concept.cpp

  NB: std::size() is only available in <array> header of C++17
*/
