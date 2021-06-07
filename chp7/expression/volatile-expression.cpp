#include <cstdio>

int num(volatile int& x) {
  x = 20;     // a dead store
  x = 30;     // (1)
  auto y = x; // (2)
  y = x;      // a redundant load (3)
  return y;
}

int main() {
  int a {};
  num(a);
  printf("a = %d\n", a); // a = 30
}

/**
 The volatile keyword guarantees that expressions (1), (2) and (3) will not be
 stripped away by the compiler for the compiler's optimization purposes.
 This can be useful if the statement are used for some side effects.
*/
