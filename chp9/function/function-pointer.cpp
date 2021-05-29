#include <cstdio>

float add (float a, int b) {
  return a + b;
}

float subtract(float a, int b) {
  return a - b;
}

int main() {
  const float first { 100 };
  const int second { 20 };

  float(*operation) (float, int) {}; // (1)
  printf("operation initialized to 0x%p\n", operation); // operation initialized to 0x00000000

  operation = &add; // (2)
  printf("&add = 0x%p\n", operation); // &add = 0x00401410
  printf("%g + %d = %g\n", first, second, operation(first, second)); // 100 + 20 = 120

  operation = subtract; // (3)
  printf("&subtract = 0x%p\n", operation); // &subtract = 0x0040141B
  printf("%g  - %d = %g\n", first, second, operation(first, second)); // 100  - 20 = 80

  using arithmethic_func = float(*)(float, int); // (4)
  arithmethic_func sum { add };   // (5)
  printf("&sum = 0x%p \n", sum); // &sum = 0x004019F0
  printf("%g + %d = %g\n", first, second, sum(first, second)); // 100 + 20 = 120
}

/**
 Function pointers provides the mechanism required to pass one function to another function.  
 This is useful in functional programming  
 
 1) Initializing a function pointer operation. 
    This function pointer operation match the signature of the add() and subtract() function.
    The value of operation is a nullptr after initialization as is seen in the printf afterwards
  2) A pointer to the add() function is assigned to operation using the address-of(&) operator
     The address-of operator is optional 
  3) A pointer to the subtract function is assigned to operation without using the optional address-of operator
  4) Defininig a type alias of a function pointer
  5) Initialiing a function pointer using the function pointer type alias and the add() function as value
*/