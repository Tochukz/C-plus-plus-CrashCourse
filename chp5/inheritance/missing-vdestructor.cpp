#include <cstdio>

struct Product {
  virtual ~Product() = default; // (1)
};

struct Book: Product {
  Book() {
    printf("Book Construct! \n");
  }

  ~Book() {
    printf("Book Destruct! \n"); 
  }
};

int main() {
  Product* book { new Book {} };
  delete book; // (2)
}

/**
 Usually, you add virtual destructors to interfaces. 
 In some rare circumstances it's possible to leak resources if you fail to mark destrcutors as virtual. 
 
 If you comment out the virtual destructor (1) in the Product base class, the Book destructor will not be invoke when 
 the delete operator is applied to a pointer to Product as seen in (2)

 Output:
   Book Construct!
   Book Destruct! 
*/
