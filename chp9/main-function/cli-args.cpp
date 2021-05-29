#include <cstdio>

int main(int argc, char* argv[]) {
  printf("Arguemnts: %d\n", argc);
  for (size_t i {}; i < argc; i++) {
    printf("%zd: %s\n", i, argv[i]);
  }
}

/**
 > .\cli-args.exe Voiolence is the last refuge of the incompetent

 Output:  
 0: D:\workspace\C-plus-plus-CrashCourse\chp9\bin\cli-args.exe
 1: Voiolence
 2: is
 3: the
 4: last
 5: refuge
 6: of
 7: the
 8: incompetent
*/