#include <cstdio>
#include <cstdint>

constexpr uint8_t max(uint8_t a, uint8_t b) {
  return a > b ? a : b;
} 

constexpr uint8_t max(uint8_t a, uint8_t b, uint8_t c) {
  return max(max(a, b), (a, c));
} 

int main() {
  constexpr uint8_t maxScore { max(75, 64, 81) };
  printf("Max Score = %d\n", maxScore); // Max Score = 81
}

/**
 Constant expression, constexpr, are expressions that can be evaluated at compile time
 If an expression can be declard constexpr, you should strongly consider doing so 
*/