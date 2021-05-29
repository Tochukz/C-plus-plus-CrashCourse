#include <cstdio>

int main() {
  auto sum = [](int x, double y) -> double { return x + y ; };
  auto add = [](auto x, double y) -> decltype(x + y) { return x + y; };
  
  int a { 5 };
  double b { 5.5 };

  printf("%d + %f = %f\n", a, b, sum(a, b));
  printf("%d + %f = %f\n", a, b, add(a, b));

}

/**
 Lambda expressions with explicit return types 

 Output: 
   5 + 5.500000 = 10.500000
   5 + 5.500000 = 10.500000
*/