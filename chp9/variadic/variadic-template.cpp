#include <cstdio>

template <typename T>
constexpr T sum(T x) { // (2)
  return x;
}

template <typename T, typename... Args> 
constexpr T sum(T x, Args... args) {
  return x + sum(args...); // (1)
}

int main() {
  printf("The answer is %d ", sum(2, 4, 6, 8, 10, 12)); // The answer is 42 
}

/**
 1) The template variadic function uses compile-time recursion to iterate over the elements of it's parameter pack
 2) The overload function handles the stopping condition; it simpler return it's argument
 
 Unlike the regular sum function with variadic, the template varidic sum function uses constexpr which means that
 the function will be evaluated at compile time

 Instead of using recursion, you could use fold expression to sum over elements of a variadic
*/