#include <cstdio>
#include <type_traits>
#include <cstddef>

template<typename T>
concept bool Averagable() { // 1
  return std::is_default_constructible<T>::value  // (2)
           && requires(T a, T b) { // (3)
               { a += b }          -> T; // (4)
               { a / size_t { 1 }} -> T; // (5)
           };
}

// Using the Averagable concept
template<Averagable T>
T mean(const T* numbers, size_t length) {
  T result {};
  for(size_t i = 0; i < length; i++) {
    result += numbers[i];
  }

  return result/length;
}

int main() {
  double scores[] { 78.5, 69.2, 87.4, 64.1, 77.9};
  double meanScore = mean<double>(scores,  sizeof(scores)/sizeof(double));
  printf("Mean Score = %f \n", meanScore); // Mean Score = 75.420000

  int marks[] {78, 69, 87, 64, 77};
  int meanMark = mean<int>(marks, sizeof(marks)/sizeof(int));
  printf("Mean Mark = %d \n", meanMark); // Mean Mark = 75

  float wins[] {78.0f, 69.5f, 87.5f, 64.0f, 77.5f};
  float meanWin = mean(wins, sizeof(wins)/sizeof(float)); 
  printf("Mean Win = %f \n", meanWin); // Mean Win = 75.300003

   // Using mean template with array of non-avaerable elements
  auto n1 = 0.1;
  auto n2 = 5.1;
  auto n3 = 3.5;
  const double* nPoiners[] {&n1, &n2, &n3};
  // mean(nPoiners, sizeof(nPoiners)/sizeof(&n1)); // error (6)
}

/**
 1) Defining a concept
 2) Using a type-traits to check type conformity
 3) Defining a Requirements
 4) Requirement 1 statement
 5) Requirement 2 statement
 6) Compilation Error:
    averagable-concept.cpp: In function 'int main()':
    averagable-concept.cpp:43:46: error: cannot call function 'T mean(const T*, size_t) [with T = const double*; size_t = unsigned int]'
    mean(nPoiners, sizeof(nPoiners)/sizeof(&n1)); // error: invalid operands of types 'const double*' and ...
                                                ^
    averagable-concept.cpp:16:3: note:   constraints not satisfied
    T mean(const T* numbers, size_t length) {
    ^~~~
    averagable-concept.cpp:6:14: note: within 'template<class T> concept bool Averagable() [with T = const double*]'
    concept bool Averagable() { // 1
                ^~~~~~~~~~
    averagable-concept.cpp:6:14: note:     with 'const double* a'
    averagable-concept.cpp:6:14: note:     with 'const double* b'
    averagable-concept.cpp:6:14: note: the required expression 'a += b' would be ill-formed
    averagable-concept.cpp:6:14: note: the required expression '(a / size_t{1})' would be ill-formed

 
 NB: You must use the -fconcept flag to compile code that uses concept 
 
 > c++ averagable-concept.cpp -o ../bin/averagable-concept -fconcepts
*/
