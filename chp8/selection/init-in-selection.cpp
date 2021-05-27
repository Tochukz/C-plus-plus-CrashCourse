#include <cstdio>

template<typename T>
constexpr const char* sign(const T& x) {
  const char* result{};
  if (x == 0) {
    result = "zero";
  } else if (x > 0) {
    result = "positive";
  } else {
    result = "negative";
  }
  return result;
}

struct TextFile {
  bool success;
  const char* content;
  size_t n_bytes;
};

TextFile read_text_file(const char* filename) {
  const char output[] {"Long output from file"};
  return {true, output, sizeof(output)};
}

int main() {
  printf("float 100 is %s\n", sign(100.0f)); // float 100 is positive
  printf("int -200 is %s\n", sign(-200));    // int -200 is negative
  printf("char 0 is %s\n", sign(char{}));    // char 0 is zero

  int score {85 };
  if (size_t price = 65000; score > 75) { // (1)
    printf("You won R%d price \n", price); // You won R65000 price
  }

  
  if (const auto [success, txt, len] = read_text_file("README.txt"); success) { // (2)
    printf("Read %d bytes: %s\n", len, txt);
  } else {
    printf("Failed tp open README.txt");
  }
}

/**
 1) init-statement in selection statements. 
 2) Another use case of init-statement in selection statement
 
 NB: Init-statement in selection statement in only available in C++17. 
    Use the -std=c++17 flag to compile the code

 > c++ .\selection-statement.cpp -o .\bin\selection-statement -std=c++17

 Output: 
  float 100 is positive
  int -200 is negative
  char 0 is zero
  You won R65000 price
  Read 22 bytes: Long outpu⌠■a
*/
