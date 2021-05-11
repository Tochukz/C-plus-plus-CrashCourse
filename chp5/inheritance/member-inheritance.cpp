#include <cstdio>

struct Product {
  int get_price() const {
    return price;
  }

  void set_Price(int price) {
    this->price = price;
  }

  virtual const char* get_description() const {
    return "A generic product!";
  }

  private:
    int price;
};

struct Book : Product {
  const char* get_description() const override {
    return "A book on C++ programming!";
  }
};

int main() {
  Product product;
  Book book;
  Product& bookRef = book;
  
  book.set_Price(700);

  printf("Product Description: %s \n", product.get_description()); // Product Description: A generic product! 
  printf("Book Description : %s \n", book.get_description());      // Book Description : A book on C++ programming! 
  printf("BookRef Description: %s \n", bookRef.get_description()); // BookRef Description: A book on C++ programming!
  printf("Book Price = %d \n", book.get_price());                  // Book Price = 700
  
}

