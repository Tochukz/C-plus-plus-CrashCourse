#include <cstdio>
#include <stdexcept>

[[noreturn]] void pitcher() { // (1)
  throw std::runtime_error { "Knuckleball"};
}

int main() {
  try {
    pitcher();
  } catch(const std::runtime_error& e) {
    printf("exception: %s\n", e.what());
  }
}

/**
 Attributes apply implementation-defined features to an expression statement.   

 1) Because you throw an exception, pitcher() never returns, hence the [[noreturn]] attribute
    The use of the attribute is optional but if used, it give the compiler information to allow 
    it to reason more completely on your code and potentially to optimize your program.

 Output: 
   exception: Knuckleball
*/