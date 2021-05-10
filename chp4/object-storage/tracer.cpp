#include <cstdio>

struct Tracer {
  Tracer(const char* name): name { name } {
    printf("%s Contructor \n", name);
  }

  void printName() {
    printf("%s \n", name);
  }

  ~Tracer() {
    printf("%s Destructor \n", name);
  }

  private: const char* name;
};

static Tracer tracer1 { "Tracer1 - Static Variable"};
thread_local Tracer tracer2 { "Tracer2 - ThreadLocal Variable"}; // (1)

int main() {
  printf("A\n");
  Tracer tracer3 { "Tracer3 - Automatic Variable"};

  printf("B\n");
  const Tracer* tracer4 = new Tracer {"Tracer4 - Dynamic Variable"};

  printf("C\n");

  // tracer2.printName(); // (2)

  // delete tracer4;
}

/**
 Output: 
    Tracer1 - Static Variable Contructor 
    A
    Tracer3 - Automatic Variable Contructor
    B
    Tracer4 - Dynamic Variable Contructor
    C
    Tracer3 - Automatic Variable Destructor
    Tracer1 - Static Variable Destructor

 1) The thread_local variable seems to be a lazy type initialization - It's constructor is not called until the instance is used like in (2)
*/