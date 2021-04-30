#include <cstdio>

int main () {
  double avo = 6.0221409e23;
  float hp = 9.75;

  printf("Avogrado's Number: %le %lf %lg \n", avo, avo, avo); // Avogrado's Number: 6.022141e+023 602214090000000010000000.000000 6.02214e+023 
  printf("Hogwarts' Platform: %e %f %g \n", hp, hp, hp);      // Hogwarts' Platform: 9.750000e+000 9.750000 9.75 
}

/**
In practice, you can omit the l prefix on the format specifiers for double, because
printf promotes float arguments to double precision
*/