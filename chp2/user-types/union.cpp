#include <cstdio>

union Rectangle {
  char name[10];
  int width;
  double height;
};

int main() {
  Rectangle rectangle;

  rectangle.width = 100;
  printf("Width = %d \n", rectangle.width); // Width = 100 

  rectangle.height = 100.05;
  printf("Height = %lf \n", rectangle.height); // Height = 100.050000 

  printf("Width = %d \n", rectangle.width); // Width = 858993459 
}

/**
 The union takes only as much memory as its largest member.
 Because all members of a union are in the same place, you can cause data corruption very easily.  
 You should avoid using unions in all but the rarest of cases. 
*/