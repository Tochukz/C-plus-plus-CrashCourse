#include <cstdio>
#include <utility>
#include <cstring>

struct Book {
  // The move constructor
  Book(Book&& book) noexcept : title (book.title), price (book.price)  { // (1) rvlaue reference argument
    book.title = nullptr;
    book.price = 0;
    printf("move construct! \n");
  }

  // The move assingment operator 
  Book& operator=(Book&& book) noexcept {
    if (this == &book) { // (2) Self reference check
        return *this;
    }
    delete[] title;
    title = book.title;
    price = book.price;
    book.title = nullptr;
    book.price = 0;
    printf("move assign! \n");
    return *this;
  }

  Book(size_t title_len, size_t price): price { price } {
    title = new char[title_len];
  }

  void set_title(char* title) {
    strcpy(this->title, title);
  }

  char* get_title() {
    return title;
  }

  ~Book() {
    delete[] title;
  }

  private: 
    char* title {};
    size_t  price {};
};

struct Product  {
  Product(Book&& book): book {std::move(book)} {

  }

  private: 
    Book book;
};

int main() {
  char proVueTitle[] {"Pro Vue.js 3"};
  Book proVue { 30, 700 };
  proVue.set_title(proVueTitle);
  printf("1) Vue Title = %s \n", proVue.get_title());          // 1) Vue Title = Pro Vue.js 3 
  
  char proExpressTitle[] {"Pro Express.js"};
  Book proExpress = std::move(proVue); // move construct! 
  printf("2) Express Title = %s \n", proExpress.get_title());  // 2) Express Title = Pro Vue.js 3
  proExpress.set_title(proExpressTitle);
  printf("3) Express Title = %s \n", proExpress.get_title()); // 3) Express Title = Pro Express.js

  char proAngularTitle[] { "Pro Angualar 6"};
  Book proAngular { 30, 750 };
  proAngular.set_title(proAngularTitle);
  printf("4) Angular Title = %s \n", proAngular.get_title()); // 4) Angular Title = Pro Angualar 6

  proAngular = std::move(proExpress); // move assign!
  printf("5) Angular Title = %s \n", proAngular.get_title()); // 5) Angular Title = Pro Express.js
  
  // 4)
  printf("6) Vue Title = %s \n", proVue.get_title());       // 6) Vue Title = (null)
  printf("7) Express Title %s \n", proExpress.get_title()); // 7) Express Title (null)
}

/**
  
*/