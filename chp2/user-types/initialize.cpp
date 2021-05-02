#include <cstdio>

struct Piano {
  int keys;
  int price;
  bool sold;
};

struct Product {
  // Initializing class members using different syntax
  bool sold = false;
  int price {199}; 
  char name[13] = {"Product Name"};

  Product() {
    printf("No argument \n");
  }
  Product(int price) {
    printf("int %d \n", price);
  }
  Product(double price) {
    printf("double %f \n", price);
  }
  Product(char x) {
    printf("char %c \n", x);
  }

  // Defining the destructor
  ~Product() {
    printf("Make way for object ending \n");
  }
};

void printArray(int numbers[], size_t arraySize) {  
  for(size_t x = 0; x < arraySize; x++) {
   printf("%d ", numbers[x]);
  }
  printf("\n");
}

int main() {
  /** Initalize Primitive */
  // Initialization to zero 
  int a = 0;
  int b {};
  int c = {};
  int d; 
  printf("%d, %d, %d, %d \n", a, b, c, d); // 0, 0, 0, 1983344429

  // Initialization to a number;
  int A = 95;
  int B { 95 };
  int C = { 95 };
  int D (95);
  printf("%d, %d, %d, %d \n", A, B, C, D); // 95, 95, 95, 95

  /** Initialie POD */
  Piano casio {}; 
  Piano yamaha = {};
  Piano stainways {88, 150000};
  Piano hoffman = {88, 220000, true};

  printf("Casio: keys = %d, price = %d, sold = %d \n", casio.keys, casio.price, casio.sold);                 // Casio: keys = 0, price = 0, sold = 0
  printf("Yamaha: keys = %d, price = %d, sold = %d \n", yamaha.keys, yamaha.price, yamaha.sold);             // Yamaha: keys = 0, price = 0, sold = 0
  printf("Stainways: keys = %d, price = %d, sold = %d \n", stainways.keys, stainways.price, stainways.sold); // Stainways: keys = 88, price = 150000, sold = 0
  printf("Hoffman: keys = %d, price = %d, sold = %d \n", hoffman.keys, hoffman.price, hoffman.sold);         // Hoffman: keys = 88, price = 220000, sold = 1


   /** Initialiing Arrays */
  int scores[] {89, 95, 78}; 
  int marks[5] {};
  int wins[5] { 72, 69, 85};
  int games[5];

  printArray(scores, 3); // 89 95 78
  printArray(marks, 5);  // 0 0 0 0 0
  printArray(wins, 5);   // 72 69 85 0 0
  printArray(games, 5);  // 1983344377 128 6422124 4199120 4201408

  /** Initailizing fully featured class */
  Product noProduct;            // No argument
  Product eProduct { };         // No argument
  Product iProduct { 190 };     // int 190
  Product dProduct { 199.96f }; // double 199.960007
  Product cProduct { 'k'};      // char k
}

/**
As a general rule to make initialization simple: use braced initializers everywhere. 
Braces initializers work as intended almost everywhere, and they cause the fewest surprises. 
For this reason, braced initialization is also called uniform initialization. 
*/