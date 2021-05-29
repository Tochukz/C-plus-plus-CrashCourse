#include <cstdio>

template<typename X, typename Y>
auto add(X x, Y y) -> decltype(x+y) {
  return x + y;
}

int main() {
  auto result1 = add(100., -10);
  auto result2 = add(100U, -20);
  auto result3 = add(char { 100 }, 54'999'900ull);

  printf("double + int = %f\n", result1);
  printf("uint + int =  %u\n", result2);
  printf("char + ulonglong = %llu\n", result3);
}

/**
  
 Output:   
   double + int = 90.000000
   uint + int =  80
   char + ulonglong = 55000000
*/