#include <cstdio>
#include <stdexcept>
#include <limits>

struct UnsignedBigInteger {
  UnsignedBigInteger(long long val): val { val } {}

  UnsignedBigInteger operator+(long num) {
    val += num;
    if (val < num) {
      throw std::overflow_error {"Warning: Overflow"};
    }
    return *this;
  }


  UnsignedBigInteger operator-(UnsignedBigInteger another) {
    val -= another.val;
    if (val > another.val) {
      throw std::underflow_error {"Warning: underflow"};
    }
    return *this;
  }

  // operator int() {
  //   if (val > std::numeric_limits<int>().max()) {
  //     throw std::runtime_error {"Warning: Narrowing!"};
  //   }
  //   return static_cast<int>(val);
  // }

  private: 
    long long val;  
};

int main() {
  UnsignedBigInteger big_number { std::numeric_limits<long long>().max() / 2};
  UnsignedBigInteger plus_1000  =  big_number + 1000;
  
}