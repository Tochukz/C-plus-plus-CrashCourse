#include <cstdio>

struct LambdaFactory {
  LambdaFactory(char input): to_count { input }, tally {} {}

  auto make_lambda() {
    return [this](const char* str) {// (1)
        size_t index {}, result {};
        while (str[index]) {
          if (str[index] == to_count) {
            result++;
          }        
          index++;  
        }
        tally += result;
        return result;
    };
  }

  const char to_count;
  size_t tally;
};

int main() {
  LambdaFactory factory {'s'};
  auto lambda = factory.make_lambda();
  printf("Tally: %zd\n", factory.tally); // Tally: 0
  printf("Sally: %zd\n", lambda("Sally sells seasheels by the seashore.")); // Sally: 7
  printf("Tally: %zd\n", factory.tally); // Tally: 7
  printf("Sailor: %zd\n", lambda("Sailort went to sea to see what he could see.")); // Sailor: 3
  printf("Tally: %zd\n", factory.tally); // Tally: 10
}

/**
 By capturing "this" by reference you are able to access the 
 members (to_count, tally) of the class
*/