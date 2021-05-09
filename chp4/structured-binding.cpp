#include <cstdio>

struct Subject {
  char name[4];
};

struct Result {
  Subject subject;
  bool passed;
};

Result get_result() {
  Subject math {"MTH"};
  return {math, true};
}

int main() {
  auto [subj, passed] = get_result();
  if (!passed) {
    printf("Failed %s! \n", subj.name);
  }
  printf("Passed %s! \n", subj.name); // Passed MTH!
}

/**
 You can return multiple values from a function by using a language 
 feature called structured binding declaration.  

 Note: Structured bindings is only available with C++17
*/