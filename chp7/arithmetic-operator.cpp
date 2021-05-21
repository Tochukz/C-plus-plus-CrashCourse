#include <cstdio>
#include <typeinfo>

int main() {
  char nine {'9'};
  short int eleven { 11 };
  bool isTrue { true };

  // (1)
  int theNine { +nine };
  int theEleven { -eleven };
  int theTrue { +isTrue};
  
  printf("Nine = %d\n", theNine);     // Nine = 57
  printf("Evelen = %d\n", theEleven); // Evelen = -11
  printf("True = %d\n", theTrue);     // True = 1

  printf("char Nine = %s\n", typeid(nine).name());   // char Nine = c
  printf("int Nine = %s\n", typeid(theNine).name()); // int Nine = i
}

/**
 1) The unary operator (+) and (minus) promotes char, short int or bool to int.
    This is a useful shorthand technique to convert these type to int
*/