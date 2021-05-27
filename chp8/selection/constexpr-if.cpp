#include <cstdio>
#include <stdexcept>
#include <type_traits>

template<typename T>
auto value_of(T x) {
  if constexpr (std::is_pointer<T>::value) {
    if (!x) { // (1)
      throw std::runtime_error{ "Null pointer dereference."};
    }
    return *x;
  } else {
    return x;
  }
}

int main() {
  unsigned long level { 8998 };
  auto level_ptr = &level;
  auto &level_ref = level;
  printf("Power level = %lu\n", value_of(level_ptr));
  ++*level_ptr;
  printf("Power level = %lu\n", value_of(level_ref));
  ++level_ref;
  printf("It's over %lu!\n", value_of(level++));
  try {
    level_ptr = nullptr;
    value_of(level);
  } catch(const std::exception& e) {
    printf("Exception: %s\n", e.what());
  }
}

/**
 At the runtime, the constexpr if statement disappears; each instantiation of value_of
 contains one branch of the selection statement or the other.  
 
 1) checks if x is a nullptr

 Output: 
  Power level = 8998
  Power level = 8999
  It's over 9000! 

 NB: if constexpr is only available with C++17. 
     Use the -std=c++17 flag to compile the code 

 > c++ .\constexpr-if.cpp -o ../bin/constexpr-if -std=c++17
*/