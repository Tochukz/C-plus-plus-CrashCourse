#include <cstdio>

struct Animal {
  virtual void eat() final {
    printf("Eating..."); 
  }
};

struct Cat: Animal {
  // (1)
  // void eat() override {}

  void sleep() {

  }
};

struct Dog final {
  void eat() {

  }
};

// (2)
// struct Pug: Dog { }

int main() {

}

/**
 1) A final method cannot be overriden.
 2) A final class cannot be inherited from i.e it cannot be a parent class
*/

