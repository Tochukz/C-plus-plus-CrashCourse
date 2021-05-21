#include <cstdio>

struct ReadOnlyInt {
  ReadOnlyInt(int val): val { val } {}

  operator int() const { // (1)
    return val;
  }

  explicit operator double() const { // (3)
    return val;
  }

  private: 
    const int val {};
};

int main() {
  ReadOnlyInt old_pay { 43000 };
  int new_pay { old_pay + 10000}; // (2)
  printf("New Pay = %d\n", new_pay); // New Pay = 53000

  double future_pay  { static_cast<double>(old_pay) + 15000.50}; // 4
  printf("Future Pay = %f\n", future_pay); // Future Pay = 58000.500000
}

/**
 1) A user defined type conversion operator/method 
 2) old_pay which of type ReadOnlyInt is implicitly converted to type int 
    thanks to the conversion method (1) defined in ReadOnlyInt 
 3) An explicit conversion method. Explicit conversion is recommended 
    over implicit conversion as the later can cause surprising behavior.
 4) Using the user defined explicit conversion operator
*/