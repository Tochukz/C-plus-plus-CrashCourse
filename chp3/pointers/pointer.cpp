#include <cstdio>

int main() {
  int count {};
  int *countAddress { &count }; 

  printf("Count = %d \n", count);                // Count = 0 
  printf("Count Address = %p \n", countAddress); // Count Address = 0061FF18 
  printf("Count = %d \n", *countAddress);        // Count = 0

  *countAddress = 1024;
  printf("Count Address = %p \n", countAddress); // Count Address = 0061FF18
  printf("Count = %d \n", *countAddress);        // Count = 1024
}

/**
&  - address-of operator 
*  - dereference operator 
-> - member-of-pointer operator
*/