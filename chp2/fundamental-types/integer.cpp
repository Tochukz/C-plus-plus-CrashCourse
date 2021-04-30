#include <cstdio>

int main() {
  unsigned short a = 0b10101010;
  int b = 0123;
  unsigned long long c = 0XFFFFFFFFFFFFFFFF;

  // Print decimal representation of integers
  printf("a = %hu \n", a);  // a = 170
  printf("b = %d \n", b);    // b = 83
  printf("c = %llu \n", c); // c = 18446744073709551615 

  // Print octal and hexadecimal representation of integers
  printf("b = %o \n", b); // b = 123
  printf("c = %x \n", c); // c = ffffffff
}
