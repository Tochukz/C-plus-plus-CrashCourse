#include <cstdio>

char read_from(char *letters, size_t len, int index) {
  char x {'\0'};
  for(size_t i = 0; i < len; i++) {
    if (index == i) {
       x = letters[i];
       break;
    }
  }
  return x;
}
void write_to(char* letters, size_t len, char x, int index) {
  bool written = false;
  for(size_t j =0; j < len ; j++) {
    if (index == j) {
      letters[j] = x;
      written = true;
    }
  }

  if (written == false) {
     printf("Error: Out of bound\n");
  }
}

int main() {
  char lower[] = "abc?e";
  char upper[] = "ABCD?";
  size_t lowerLen = sizeof(lower)/sizeof(char);
  size_t upperLen = sizeof(upper)/sizeof(char);
  char* upper_ptr = upper; // equivalent to &upper[0] 
            
  write_to(lower, lowerLen, 'd', 3);
  write_to(upper, upperLen, 'E', 4);
  write_to(upper, upperLen, 'F', 7); // Error: Out of bound
  char c1 = read_from(lower, lowerLen , 3);
  char c2 = read_from(upper, upperLen, 4);
  char c3 = read_from(upper, upperLen, 5);

  printf("c1 = %c \n", c1); // c1 = d
  printf("c2 = %c \n", c2); // c2 = E
  printf("c3 = %c \n", c3); // c3 =





}