#include <cstdio>

struct School {
  char name[256];
};

void print_name(School* school_ptr) { 
  printf("School: %s \n", school_ptr->name);
}

void print_names(School* schools, size_t schoolsCount) {
  for(size_t i = 0; i < schoolsCount; i++) {
    printf("%s ", schools[i].name); // (4)
  }
  printf("\n");
}

int main() {
  int scores[] {90, 87, 79, 82, 91};
  int* scores_ptr = scores; // points to 90 - the first element of the array  (1)

  printf("Scores Address = %p \n", scores_ptr);   // Scores Address = 0061FF10
  printf("Score Pnt value = %d \n", *scores_ptr); // Score Pnt value = 90

  School schools[] {"Uniben", "Wits", "Unilag"};
  print_name(schools); // School: Uniben (2)
  print_names(schools, sizeof(schools)/sizeof(School)); // Uniben Wits Unilag (3)


  // Pointer to element of an array
  int* third_elem_ptr1 = &scores[2];
  int* third_elem_ptr2 = scores + 2; // using pointer arithmetic
  printf("Pointer to third element = %p \n", third_elem_ptr1); // Pointer to third element = 0061FEF8 
  printf("Pointer to third element = %p \n", third_elem_ptr2); // Pointer to third element = 0061FEF8 

}

/**
 1) The array assiged to *scores_ptr decays into a pointer to the first element of the array
 2) The array passed to the print_name function decays into a pointer to the first element of the array
 3) When you pass arrays to function you normally pass the pointer to the first element and the array length 
    This pointer-plust-size approach to passing arrays is ubiquitous in C-style APIs, for example in Windows or Linux system programming.  
 4) The sqare bracket, [], works with pointers just as with arrays
*/