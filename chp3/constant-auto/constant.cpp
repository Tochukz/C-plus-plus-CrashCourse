#include <cstdio>

void printMusic(const char* notes) { // const Argument (1)
  printf("Notes in music %s \n", notes); 
} 

struct Book {
  Book(int book_id) {
   this->book_id = book_id;
  }
  int get_book_id() const { // const Method (2)
    return book_id;
  }
  private: int book_id;
};

struct Shirt {
  Shirt(char* color, const int size): ShirtColor { color }, ShirtSize {size} { // (3)

  }
  void printShirt() {
    printf("A %s size %d Shirt \n", ShirtColor, ShirtSize);
  }
  const char* ShirtColor;
  private: const int ShirtSize;
};

void printBookId(const Book& book) {
  int bookId = book.get_book_id(); // const object calls a const method (4)
  printf("Book ID = %d \n", bookId);
}

int main() {
  char musicNotes[] {"ABCDEFG"};
  printMusic(musicNotes); // Notes in music ABCDEFG 

  Book cPlusPlus { 109 };
  printBookId(cPlusPlus); // Book ID = 109
   
  char color[] {"White"};
  Shirt shirt { color, 16 };
  shirt.printShirt(); // A White size 16 Shirt
}

/**
1) const argument cannot be modified in the function's body 
2) const method cannot modify the current object's state
3) Member Initializer List. You can use it to initalize const members.
4) A const reference/pointer cannot invoke methods that are not const
   because  methods that are not const might modify the object's state
*/