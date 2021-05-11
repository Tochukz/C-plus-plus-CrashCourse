#include <cstdio>
#include <utility>

void ref_type(int &x) { // (1)
  printf("lvalue %d \n", x);
}

void ref_type(int &&x) { // (2)
  printf("rvalue %d \n", x);
}

int main() {
  int y = 5;
  ref_type(y);            // lvalue 5 
  ref_type(std::move(y)); // rvalue 5 (3)
  ref_type(5);            // rvalue 5 
  ref_type(2+y);          // rvalue 7 

  printf("y = %d \n", y);
}

/**
 An lvalue is any value that has a name, and an rvalue is anuthing that isn't an lvalue. 

 1) A function that take an lvalue reference
 2) A function that take an rvalue reference
 3) You use std::move() to cast an lvalue to an rvalue. The std:move function doesn’t actually move anything it casts.
    If an lvalue is at hand, moving is suppressed. If an rvalue is at hand, moving is enabled.
    You can perform two actions on a moved-from object: destroy it or reassign it. 

*/