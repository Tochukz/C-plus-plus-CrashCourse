#include <cstdio>
#include <cstdint>

struct RandomNumberGen {
  explicit RandomNumberGen(uint32_t seed): number { seed }, i {} {}
  
  uint32_t next(); // (1)
  
  size_t get_iterator() const; // (2)

  private: 
    size_t i;
    uint32_t number;
};

int main() {
  RandomNumberGen randGen { 0x4c4347 };
  while (randGen.next() != 0x474343) {
   // Do nothing
  }
  printf("%zd \n", randGen.get_iterator()); // 927393188
}

uint32_t RandomNumberGen::next() { // (3)
  number = 0x3fffffff & (0x41c64e6d * number + 12345 ) % 0x80000000;
  i++;
  return number;
}

size_t RandomNumberGen::get_iterator() const { // (4)
  return i;
}

/**
 A class method declaration can be separated from it's definition.
 Separating declaration and definition provides major benefits for multiple-source file programs

 1) Declaration of the next() method 
 2) Declaration of the get_interator() method 
 3) Definitin of the next() method 
 4) Definition of the get_integrator() method
*/ 