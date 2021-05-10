#include <cstdio>

int main() {
  int* count_ptr = new int;
  int* score_ptr = new int { 94 };

  printf("Count Pointer = %p, Score Pointer = %p \n", count_ptr, score_ptr); // Count Pointer = 00A298B0, Score Pointer = 00A298C0
  printf("Count Value = %d, Score Value = %d \n", *count_ptr, *score_ptr);   // Count Value = 10656408, Score Value = 94 

  delete count_ptr;
  delete score_ptr;

  printf("Count Pointer = %p, Score Pointer = %p \n", count_ptr, score_ptr); // Count Pointer = 00A298B0, Score Pointer = 00A298C0
  printf("Count Value = %d, Score Value = %d \n", *count_ptr, *score_ptr);   // Count Value = 10656408, Score Value = 94
}

/**
 After the delete expression for a pointer is exxecuted, the compiler may leave the object's memory untouched 
 until the program reuses it for some other purposes. 
 You would have to implement a custom destructor to, for example, zero out some sensitive contents. 

 You must make sure that dynamic objects you allocate are also deallocated. Failure to do so causes memory leaks 
 in which memory that is no longer needed by your program isn't released.   
*/