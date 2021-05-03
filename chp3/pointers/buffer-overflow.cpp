#include <cstdio>

int main() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = upper; // equivalent to &upper[0] 
            
  lower[3] = 'd';     // equivalent to  Pointer Arithmetic : *(lower + 3) = 'd'; 
  upper_ptr[3] = 'D'; // equivalent to  Pointer Arithmetic : *(upper_ptr + 3) = 'D'

  char letter_d = lower[3];     // equivalent to pointer arithmetic: *(lower + 4);
  char letter_D = upper_ptr[3]; // equivalent to pointer aithmetic: *(upper_ptr + 4);

  printf("Lower: %s \n", lower);     // Lower: abcde 
  printf("Upper: %s \n", upper_ptr); // Upper: ABCDE 

  printf("letter_d = %c, letter_D = %c", letter_d, letter_D); // letter_d = d, letter_D = D

  lower[7] = 'g'; // Out of bound. (1)

}

/**
 1) When you try to assign using the index of an array which is out of bound, you are writting out-of-bounds memory 
     and gone past the storage allocated to the array. No bound check occurs so the code compiles without warning.
     At runtime, you get undefined behavior and can result in access violations, program crashes, security vulnerabilities and corrupted data.
 */