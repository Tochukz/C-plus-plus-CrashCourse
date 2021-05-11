#include <cstdio>

// An abstract class
struct Product {
  // A pure virtual function (1)
  virtual const char* get_title() const =0;

  int get_price() const {
    return price;
  }

  void set_price(int price)  {
    this->price = price;
  }  

  private:
    int price;
};

struct Book : Product {
  const char* get_title() const override {
    return "A programming book on C++!";
  }
};

int main() {
  Book book;
  book.set_price(450);

  printf("Book Title: %s \n", book.get_title()); // Book Title: A programming book on C++! 
  printf("Book Price: %d", book.get_price());    // Book Price: 450
}

/**
 You call methods with both the virtual keyword and =0 suffix pure virtual methods. 
 You cannot instantiate a class containing any pure virtual methods.
*/