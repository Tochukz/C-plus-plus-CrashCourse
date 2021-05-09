#include <cstdio>
#include <stdexcept>

void buy(int price) noexcept {
   if (price < 0) {
     // throw std::runtime_error {"Buying Error!"};
   }
   printf("Your order was successful!\n");
}

int main() {
  int cost { -70 }; 
  buy(cost);
}

/**
 When a function that is marked with noexcept throws and excepting, 
 the C++ runtime will call the std::terminate function  that by default 
 will exit the program via abort.

 Marking a function noexcept enables some code optimizations that rely
 on the function’s not being able to throw an exception. Essentially, the compiler
 is liberated to use move semantics, which may be faster.
*/