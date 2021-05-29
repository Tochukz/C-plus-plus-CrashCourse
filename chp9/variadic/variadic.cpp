#include <cstdio>
#include <cstdint>
#include <cstdarg>

int sum(size_t n, ...) {
  va_list args; // (1)
  va_start(args, n); // (2)
  int result {};
  while(n--) {
    auto next_element = va_arg(args, int);
    result += next_element;
  }
  va_end(args);
  return result;
}

int main() {
  // 6 is the size, the remainder is the variable argument of size 6
  printf("The answer is %d", sum(6, 2, 4, 6, 8, 10, 12)); // The answer is 42
}

/**
 1) All variadic function must declare a va_list 
 2) You initialize the va_list with va_start which take 2 argeuments: va_list and its size which is n

 Variadic functions are unsafe and a common source of security vulnerabilities: 
 * Varidics arguments are not type-safe
 * The number of elements in the variadics argument must be tracked separately
 
 Varidic template provide a safer and more perfomant way to implement varidic functions
*/