#include <cstdio>
#include <cstdint>
#include <functional>

struct CountIf {
  CountIf(char x): x { x } {}
 
 size_t operator()(const char* str) const {
   size_t index {}, result {};
   while (str[index]) {
     if (str[index] == x) {
       result++;
     }
     index++;
   }
   return result;
 }

  private:
    const char x;
};

size_t count_spaces(const char* str) {
  size_t index{}, result {};
  while(str[index]) {
    if(str[index] == ' ') {
      result++;
    }
    index++;
  }
  return result;
}

std::function<size_t(const char*)> funcs[] { // (1)
  count_spaces,
  CountIf { 'e' },
  [](const char* str) {
    size_t index {};
    while(str[index]) {
      index++;
    }   
    return index;
  }
};

auto text = "Sailor went to sea to see what he could see.";

int main() {
  size_t index {};
  for(const auto& func: funcs) {
    printf("func #%zd: %zd\n", index++, func(text));
  }
}

/**
 1) A function array is initialized with three callable objects: 
   1. A static function 
   2. A function object, (i.e a class instance that imlements the function operator)   
   3. A lambda expression

 Output: 
   func #0: 9
   func #1: 7
   func #2: 44 
*/