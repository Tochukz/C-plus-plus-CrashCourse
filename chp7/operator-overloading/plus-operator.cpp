#include <cstdio>
#include <stdexcept>
#include <limits>

struct Person {
  Person(unsigned int age): age { age } { }

  Person operator+(unsigned int years) const { // (1)
    Person person { age + years};
    if (person.age < age) {
      throw std::overflow_error{ "Overflow!" };
    }
    return person;
  }

  const  unsigned int age;
};

int main() {
  Person johnson { 25 };
  Person john = johnson + 15;
  printf("John's Aged = %d\n", john.age); // John's Aged = 40

  try {
    Person mcjohn = johnson + std::numeric_limits<unsigned int>::max();
  } catch(const std::overflow_error& e) {
    printf("Exception: %s\n", e.what());
  }
}

/**
 1) The operator overload method, operator+(), allows you to add an ordinary unsinged int 
     to a Person object to produce a new Person object with the correct age. 

  Output 
    John's Aged = 40
    Exception: Overflow!
*/