#include <cstdio>
#include <cstdint>

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

int main() {
  CountIf s_counter { 's' };
  auto sally = s_counter("Sally sells seashells by seashore");
  printf("Sally: %zd\n", sally); // Sally: 7

  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor); // Sailor: 3

  auto buffalo = CountIf { 'f' }("Buffalo buffalo buffalo"
                                  "buffaloo buffallo buffalo");
  printf("Buffalo: %zd\n", buffalo); // Buffalo: 12            
}

/**
 CountIf implements a function-call operator: operator()() 
 A type that implements a function-call operator is called a function type
 An instance of a function type is called a function object
 You can invoke a function object as if it were a function 
*/