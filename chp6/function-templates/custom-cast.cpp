#include <cstdio>
#include <stdexcept>
#include <climits>

template<typename To, typename From>
To custom_cast(From value) {
  const auto converted = static_cast<To>(value);
  const auto reversed = static_cast<From>(converted);
  if (value != reversed) {
    throw std::runtime_error("Narrowing Conversion!");
  }
  return converted;
}

int main(){
  int x { 30'000  };
  short a = custom_cast<short>(x);
  printf("x (%d) = a (%d) \n", x, a); // x (30000) = a (30000)

  try {
    int y { SHRT_MAX + 1};
    short b = custom_cast<short>(y); 
    printf("y (%d) = b (%d) \n", y, b);
  } catch(const std::runtime_error& ex) {
    printf("Error: %s \n", ex.what());
  }
}

/**
 
 Output 
   x (30000) = a (30000)
   Error: Narrowing Conversion! 
 */
