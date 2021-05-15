#include <stdexcept>

template <size_t Index, typename T, size_t Length> // (1)
T& get(T (&arr)[Length]) {
  static_assert(Index < Length, "Out-of-bound access");
  return arr[Index];
}

int main() {
  int digits[] {1, 2, 2, 0};
  printf("%d %d %d \n", get<0>(digits), get<1>(digits), get<2>(digits)); // 1 2 2
  get<3>(digits) = get<1>(digits) + get<2>(digits);
  printf("%d \n", get<3>(digits)); // 4
  // printf("%d", get<4>(digits)); // Error (2)
}

/**
 Non-Type Tempate Parameter 

 1) Index and Length are non-type template parameters 
 2) Error due to the failed assertion 
*/