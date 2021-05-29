#include <cstdio>
#include <cstdint>

template<typename Fn>
void transform(Fn fn, const int* input, int* output, size_t length) {
  for(size_t i {}; i < length; i++) {
    output[i] = fn(input[i]);
  }
}

int main() {
  int num1 { 5 };
  float num2 { 15.75 };
  double num3 { 100.05 };
  int fiveSquare = [](int x){ return x*x; }(num1);
  float sum = [](float x, float y) constexpr { return x+y; }(num1, num2);
  double diff = [](float x, double y) constexpr -> double { return x - y; }(num2, num3);

  printf("%d^2 = %d\n", num1, fiveSquare);
  printf("%d + %f = %f\n", num1, num2, sum);
  printf("%f - %f = %f\n", num2, num3, diff);

  auto addTo = [](int x, int y = 10) { return x + y; };
  printf("addTo(20) =  %d\n", addTo(20)); 
  printf("addTO(15, 25) = %d\n", addTo(15, 25)); 

  const size_t len { 3 };
  int base[] {1, 2, 3}, form1[len], form2[len], form3[len];
  transform([](int x){ return 1; }, base, form1, len);
  transform([](int x){ return x; }, base, form2, len);
  transform([](int x){ return 10*x+5; }, base, form3, len);
  for (size_t i {}; i < len; i++) {
    printf("Element %zd: %d %d %d\n", i, form1[i], form2[i], form3[i]);
  }
}

/**
 Lambda expression usage is as follows:  
 [capture] (parameters) modifiers -> return-type { body }
 only he captures and the body re required; everthing elase is optional

 The [capture] component is analogous to the constructor of a function type

 NB: constexpr lambda is only available with C++17
   Use -std=c++17 to compile the code 

 > c++ .\lambda-expression.cpp -o .\bin\lambda-expression -std=c++17

 Output: 
   5^2 = 25
   5 + 15.750000 = 20.750000
   15.750000 - 100.050000 = -84.300000 
   addTo(20) =  30
   addTO(15, 25) = 40
   Element 0: 1 1 15
   Element 1: 1 2 25
   Element 2: 1 3 35
*/