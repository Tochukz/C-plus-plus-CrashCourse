#include <cstdio>
#include <stdexcept>

struct Person {
  void forget(int x) {
    if (x == 0xFACE) {
      throw std::runtime_error {"oxFACE not acceptable!"};
    }
    printf("Forgot 0x%x \n", x);
  }
};

int main() {
  Person person; 
  try {
    person.forget(0xC0DE);
    person.forget(0xFACE); 
    person.forget(0xc0ffee);
  } catch(const std::runtime_error& err) {
    printf("Caught Exception: %s \n", err.what());
  }
}

/**
 Output:
   Forgot 0xc0de 
   Caught Exception: oxFACE not acceptable! 
*/