#include <cstdio>
#include <functional>

void print_name() {
  printf("Name is Chucks\n");
}
int main() {
  std::function<void()> local_print {[] (){ printf("City is CapeTown\n"); }}; // (1)
  local_print(); // City is CapeTown

  local_print = print_name; // (2)
  local_print(); // Name is Chucks
}

/**
 1) Using the constructor to assign a callable object to a function type
2) Using the assignent operator to assign a callable object to a function type
*/