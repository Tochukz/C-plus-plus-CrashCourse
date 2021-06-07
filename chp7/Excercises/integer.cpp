#include <cstdio>
#include <stdexcept>
#include <limits>

struct BigInteger {
  BigInteger(int val): val { val } {}

  BigInteger operator+(int num) {
    val += num;
    if (val < num) {
      throw std::overflow_error {"Warning: Overflow"};
    }
    return *this;
  }


  BigInteger operator-(BigInteger another) {
    val -= another.val;
    if (val > another.val) {
      throw std::underflow_error {"Warning: underflow"};
    }
    return *this;
  }

  private: 
    int val;  
};

int main() {
  int half_max { std::numeric_limits<int>().max() / 2 } ;
  BigInteger big_number { half_max };
  BigInteger plus_1000  { big_number + 1000 };
  BigInteger plus_2000 { half_max + 2000 };
  plus_2000 - plus_1000;
  
  printf("HalfMax = %d\n", half_max);     // HalfMax= 1073741823
  printf("BigNumber = %d\n", big_number); // BigNumber = 1073742823
  printf("Plus1000 = %d\n", plus_1000);   // Plus1000 = 1073742823
  printf("Plus2000 = %d\n", plus_2000);   // Plus2000 = 1000
 }