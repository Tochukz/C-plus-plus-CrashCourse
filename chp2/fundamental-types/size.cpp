#include <cstdio>
#include <cstddef>

int main() {
  size_t charSize = sizeof(char);
  size_t shortSie = sizeof(short);
  size_t intSize = sizeof(int);
  size_t longSize = sizeof(long);
  size_t llSize = sizeof(long long);

  size_t hexNumber = 0x348039fd;

  printf("char size = %zd \n", charSize);  // char size = 1
  printf("short size = %zd \n", shortSie); // short size = 2 
  printf("int size = %zd \n", intSize);    // int size = 4
  printf("long size = %zd \n", longSize);  // long size = 4
  printf("long long size = %zd \n", llSize); // long long size = 8

  printf("hex number = %zx", hexNumber); // hex number = 348039fd
}

/**
 The size_t object guarantee that their maximum values are sufficient to represent the maximum size in bytes of all objects.   
 Technically this means a size_t could take 2 bytes or 200 bytes depending on the implentation.   
*/