#include <cstdio>
#include <functional>

int main() {
  std::function<void()> func; // (1)
  try {
    func();
  } catch(const std::bad_function_call& e) {
    printf("EXception: %s", e.what());
  }
}

/**
 A function type is defined but not explicitly initialized. 
 It thus have an equivalent of an empty function as it default value. 

 Output: 
   EXception: bad_function_call
 */