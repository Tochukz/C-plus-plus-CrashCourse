#include <cstdio>
#include <cstdint>

template<typename Fn, typename T>
void transform(Fn fn, const T* input, T* output, size_t len) {
  for (size_t i {}; i < len; i++) {
    output[i] = fn(input[i]);
  }
}

int main() {
  constexpr size_t len { 3 };
  int base_int[] {1, 2, 3}, form1[len];
  float base_float[] {10.f, 20.f, 30.f},  form2[len];
  auto translate = [](auto x) { return 10 * x + 5; }; // (1)
  transform(translate, base_int, form1, len);
  transform(translate, base_float, form2, len);

  for(size_t i{}; i < len; i++) {
    printf("Element %zd: %d %f\n", i, form1[i], form2[i]);
  }
}

/**
 1) A generic lambda  expression
 
 Output: 
   Element 0: 15 105.000000
   Element 1: 25 205.000000
   Element 2: 35 305.000000 
*/