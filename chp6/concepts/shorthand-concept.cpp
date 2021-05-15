#include <cstdio>
#include <type_traits>
#include <cstddef>

struct User {};

template<typename T>
concept bool Ordered() {
  return requires(T* n) {
     { n[0] > n[1]} -> bool;
  };
}

// prefix omitted (1)
size_t min_index(Ordered* numbers, size_t length) {
  size_t min_index {};
  for (size_t i { 1 }; i < length; i++) {
     if (numbers[i] < numbers[min_index]) {
        min_index = i;
     }     
  }
  return min_index;
}

int main() {
  int numbers[] {-20, 0, 100, 400, -21, 5123 };
  printf("%zd\n", min_index(numbers, 6)); // 4

  unsigned short figures[] { 42, 51, 900, 400};
  printf("%zd\n", min_index(figures, 4)); // 0

  User users[] { User{}, User{} };
  // min_index(users, 2); // Error (2)
}

/**
 1) If a template parameter is only used to declare the type of a function parameter, 
 you can omit the template prefix entrirely.
 Whenever you use a concept as part of a function definition, 
 that function becomes a template.  

 2) Error from the Ordered concept
*/
