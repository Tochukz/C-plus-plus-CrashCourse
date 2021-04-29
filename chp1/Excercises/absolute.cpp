#include <cstdio>

int absolute_value(int x) {
 if (x > 0) {
    return x;
 }
 return x * -1;
}

int sum(int x, int y) {
  return x + y;
}

int main() {
    int n = -9;
    int x = 7, y = 11;
    printf("The absolute value of %d is %d \n", n, absolute_value(n));
    printf("The sum of %d and %d is %d", x, y, sum(x, y));
}