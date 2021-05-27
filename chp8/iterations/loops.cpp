#include <cstdio>
#include <cstdint>
#include <limits>

bool has_overflown(uint8_t& x) {
  const auto original = x;
  x *= 2;
  return original > x;
}

int main() {
  
  printf("max uint8_t = %d\n", std::numeric_limits<uint8_t>::max());

  uint8_t a { 1 };
  while(!has_overflown(a)) {
    printf("%u ", a);
  }

  printf("\n");
  uint8_t b { 1 };
  do {
   printf("%u ", b);
  } while(!has_overflown(b));

  printf("\n");
  const int values[] {1, 3, 5, 8, 9};
  for (uint8_t i {}; i < 5; i++) {
    printf("%u ", values[i]);
  }

  printf("\n");
  for(int val: values) {
    printf("%d ", val);
  } 
}

/**
 A range (or range expression) is an object that the rangebased for loop knows how to iterate over
 Output: 
   max uint8_t = 255
    2 4 8 16 32 64 128 
    1 2 4 8 16 32 64 128
    1 3 5 8 9
    1 3 5 8 9  
*/ 