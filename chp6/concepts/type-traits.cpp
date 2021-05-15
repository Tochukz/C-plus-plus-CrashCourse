#include <cstdio>
#include <type_traits>
#include <cstdint>

constexpr const char* as_str(bool x) {
  return x ? "True" : "False";
}

int main() {
  printf("%s\n", as_str(std::is_integral<int>::value));
  printf("%s\n", as_str(std::is_integral<const int>::value));
  printf("%s\n", as_str(std::is_integral<char>::value));
  printf("%s\n", as_str(std::is_integral<uint64_t>::value));
  printf("%s\n", as_str(std::is_integral<int&>::value));
  printf("%s\n", as_str(std::is_integral<int*>::value));
  printf("%s\n", as_str(std::is_integral<float>::value));
}

/**
 Output: 
    True
    True
    True
    True
    False
    False
    False 
*/