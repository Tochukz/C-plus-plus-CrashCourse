#include <cstdio>

/** A POD (plain-old-data) class */
struct Book {
  char title[256];
  int  year;
  int pages;
  bool hardcover;
};

int main() {
  Book cPlusPlus;
  cPlusPlus.pages = 749;
  printf("Book is %d pages.", cPlusPlus.pages);
}

/**
 As a general rule you should order members from largest to smallest within POD definitions.     
*/