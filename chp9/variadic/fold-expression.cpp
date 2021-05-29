#include <cstdio>

template<typename... T>
constexpr auto sum(T... args) {
  return (... + args); // (1)
}

int main() {
  printf("The anwser is %d.", sum(2, 4, 6, 8, 10, 12)); // The anwser is 42.
}

/**
1) Fold expression is used to plus (+) all the elements of the variadic. 
  Fold expression syntax: 
    (... binary-operator parameter-pack)

 NB: Fold expression is only available on C++17  
   Use the -std=c++17 flag to complie the code 

  > c++ .\fold-expression.cpp -o ./bin/fold-expression -std=c++17
*/