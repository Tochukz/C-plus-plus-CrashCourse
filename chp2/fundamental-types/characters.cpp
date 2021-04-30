#include <cstdio> 

int main() {
    char x = 'M';
    wchar_t y = L'Z';

    printf("Window binaries start with %c %lc .\n", x, y); // Window binaries start with M Z .
}

/** 
 All characters except char must be prepended by a prefix: 
  L for wchar_t, u for char16_t, and U for char32_t.
*/