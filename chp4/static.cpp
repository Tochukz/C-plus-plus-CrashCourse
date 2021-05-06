#include <cstdio>

static int Price { 250 };

void increasePrice(int increase) {
  Price += increase;
  printf("New Price: %d \n", Price);
}

struct Book {
  static int BookPrice;

  static void increasePrice(int increase) {
    BookPrice += increase;
    printf("New Book Price = %d \n", BookPrice);
  } 
};

int Book::BookPrice = 700 ;

int main() {
  increasePrice(50); // New Price: 300 
  increasePrice(40); // New Price: 340 

  Book::increasePrice(60);  // New Book Price = 760 
  Book::increasePrice(140); // New Book Price = 900
}