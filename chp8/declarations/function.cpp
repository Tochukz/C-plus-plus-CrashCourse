#include <cstdio>
#include <cstdint>

void randomize(uint32_t&) ;

int main() {
  size_t i {};
  uint32_t number { 0x4c4347 };
  while (number != 0x474343) {
    randomize(number);
    i++;
  }
  printf("%zd \n", i); // 927393188
}


void randomize(uint32_t& x) {
  x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}

/**
 randomise() to not produce random numbers 
*/