#include <cstdio>
#include <stdexcept>

constexpr void assert_that(bool statement, const char* message) {
  if (!statement) {
    throw std::runtime_error { message };
  }
}

int main() {
  assert_that(1 + 2 > 2, "1 + 2 should be greater than 2" );
  assert_that(24 == 42, "24 should be equal to 42");
}

/**
 Output 
   terminate called after throwing an instance of 'std::runtime_error'
   what():  24 should be equal to 42
 */