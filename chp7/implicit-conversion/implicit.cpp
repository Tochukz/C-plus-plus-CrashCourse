#include <cstdio>

void print_addr(void* addr) {
  printf("ox%p\n", addr);
}

int main() {
  int x { 10 };
  print_addr(&x);      // ox0061FF1C
  print_addr(nullptr); // ox00000000

  int yes { 65 };
  int no {};

  bool yes_val { yes };
  bool no_val { no };
  bool px { &x };
  bool py {nullptr};
  printf("Yes = %d\n", yes_val); // Yes = 1  
  printf("No = %d\n", no_val);   // No = 0    
  printf("px = %d\n", px);       // px = 1 
  printf("py = %d\n", py);       // py = 0   
}

/**
 Pointers, integers, and floating-point numbers can all be implicitly converted to bool objects
*/