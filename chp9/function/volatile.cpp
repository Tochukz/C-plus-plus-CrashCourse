#include <cstdio>

struct Animal {
  Animal(char* name): name { name } {}

  void sleep() {
    printf("%s is sleeping \n", name);
  }

  void eat() volatile { 
    printf("%s is eating \n", name);
  }

  void walk() const {
    printf("%s is walking \n", name);
  }

  private:
    char* name; 
};

int main() {
  char name1[] {"Dog"};
  volatile Animal dog { name1 };
  //dog.sleep(); // (1)  
  // dog.walk(); // (2)
  dog.eat();

  char name2[] {"Cat"};
  const Animal cat { name2 };
  // cat.sleep(); // (3)
  // cat.eat(); // (4)
  cat.walk();
}

/**
 Only methods marked `volatile` can be invoked on a volatile instance a the class. 
 Similarly, only methods marked `const` to be invoked on a constant instance of a class.

Output: 
  Dog is eating 
  Cat is walking 

 1) Error: dog was initialized as a volatile instance, therefore only the
    innstance method marked volatile can be called on it's object 
 2) Error: same as (1)
 3) Error: cat was initialized as a const instance , therefore only the
    instance method that are marked const can be called on it's object
 4) Error: same as (3)
 */