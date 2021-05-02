#include <cstdio>

/** A scoped enum*/
enum class Animal {
  Dog, 
  Cat, 
  Lion,
  Goat
};

Animal cat = Animal::Cat;

/** An unscoped enums */
enum Electronic {
  Computer, 
  Tevevision,
  Radio,
  Fan
};

int main () {
  Animal lion = Animal::Lion;
  
  switch(lion) {
    case Animal::Dog:  {
        printf("A Dog it is! \n");
      }
      break;
    case Animal::Cat: {
        printf("He is a Cat! \n");
      }
      break;
    case Animal::Goat: {
       printf("What a Goat! \n");
      }
      break;
    case Animal::Lion: {
        printf("Majestic Lion! \n");
      }  
      break;
    default: {
        printf("Error: unknown animal! \n");
    }
  }

  Electronic computer = Computer;
  printf("Computer = %d \n", computer); // Computer = 0 
}

/**
 Unscoped enums are less safe to use than scoped enums. 
 Always use scoped enums where possible  

 The braces in each case of the switch statement is optional but highly recommeded
*/