#include <cstdio>
#include <cstdint>

int main() {
  char to_count {'s'};
  size_t tally {};
  auto s_counter = [to_count, &tally](const char* str) {
    size_t index {}, result {};
    while(str[index]) {
      if (str[index] == to_count) {
          result++;
      }
      index++;
    }
    tally += result;
    return result;
  };

  printf("Tally: %zd\n", tally);
  auto sally = s_counter("Sally sells seasheels by the seashore.");
  printf("Sally: %zd\n", sally);

  printf("Tally: %zd\n", tally);
  auto salior = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", salior);

  printf("Tally:  %zd\n", tally);
}

/**
 A lambda can capture by reference or by value. 
 By default, lambdas capture by value. 
 A lambda's capture list is analogous to a function type's constructor.
 
 Output: 
    Tally: 0
    Sally: 7
    Tally: 7
    Sailor: 3
    Tally:  10
*/