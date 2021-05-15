#include <cstdio>
#include <type_traits>  

template<typename T> 
T mean(T* numbers, size_t length) { 
  // using static_assert (1)
  static_assert(std::is_default_constructible<T>(), "Type must be default constuctible.");
  static_assert(std::is_copy_constructible<T>(), "Type must be copy constructible");
  static_assert(std::is_arithmetic<T>(), "Type must support addition and division.");
  static_assert(std::is_constructible<T, size_t>(), "Type must be constructible from size_t.");

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
  // mean(nPoiners, sizeof(nPoiners)/sizeof(&n1)); // error (2)
}

/**
1) You can use type traits in combination with static_assert to achieve a similar result as 
using a concept.
Using static_assert as a proxy for concept is a hack, but it's widely uses.  

2) Error due to failed assertions
*/