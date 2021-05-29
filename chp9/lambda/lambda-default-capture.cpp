#include <cstdio>

int main() {
  char x {'s'};
  size_t total {};
  auto s_counter = [=](const char* str) mutable { // (1)
    size_t index{}, result {};
    while(str[index]) {
      if (str[index] == x) {
          result++;
      }    
      index++;
    }
    total += result; // (3)
    return result;
  };
 
  printf("Total %d\n", total); // Total 0
  size_t sally = s_counter({"Sally sells seashell by the seashore"});
  printf("Sally = %d\n", sally); // Sally = 6

  char y {'p'};
  size_t tally {};
  auto p_counter = [&](const char* str) { // (2)
    size_t index {}, result {};
    while(str[index]) {
      if (str[index] == y) {
        result++;
      }
      index++;
    }
    tally += result;
    return result;
  };

  printf("Tally %d\n", tally); // Tally 0

  size_t peter  = p_counter({"Peter packer pack a pack of pickel in a pickel port"});
  printf("Peter %d\n", peter); // Peter 6
  printf("Tally %d\n", tally); // Tally 6

  size_t paul = p_counter({"Paul pass though payrue to purchase piper for the purpet master"});
  printf("Paul %d\n", paul);   // Paul 7
  printf("Tally %d\n", tally); // Tally 13
}

/**
 With default capture you can capture all the automatic variable used within the lambda expresion

 1) Default capture by value: [=]
 2) Default capture by reference: [&]
 3) You cannot modify a value-captured variable unless the lambda is marked with the mutable modifier
    Without the mutable modifier you may not call non-const  on the object

 * You can mix default capture and names capture: [&, x] i.e default capture by referenece and x captured by value

 It’s far better to declare captures explicitly. 
 If you catch yourself saying “I’ll just use a default capture because there are too many variables to list out,” 
 you probably need to refactor your code
 */