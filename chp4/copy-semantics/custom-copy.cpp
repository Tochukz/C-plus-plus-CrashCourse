#include <cstdio>
#include <cstring>

struct Book { 
  // The Copy constructor
  Book(const Book& book) {   
    size_t title_len {20 }; // { sizeof(book.title)/sizeof(char)}; // Wrong size
    title = new char[title_len];
    strncpy(title, book.title, title_len);
  }

  // The Copy Assignment Operator
  Book& operator=(const Book& book) {
    size_t title_len {20 }; 
    title = new char[title_len];
    strncpy(title, book.title, title_len);
    return *this;
  }

  Book(size_t title_len) {
    title = new char[title_len];
    title[0] = 0;
  }

  void set_title(const char* title) {
    strcpy(this->title, title);
  }

  char* get_title() {
    return this->title;
  }

  void printAddress(int x) {
    printf("%d) Title Address: %p \n", x, &title);
  }

  ~Book() {
    delete[] title;
  }

  private: 
    char* title {};
};

int main() {
  char angularTitle[] {"Pro Angular 6"};
  Book proAngular { 20 };
  proAngular.set_title(angularTitle);
  printf("1) Angular Title = %s \n", proAngular.get_title()); // 1) Angular Title = Pro Angular 6 
  proAngular.printAddress(2);                                 // 2) Title Address: 0061FEFC

  // Using the Copy constructor
  char cPPTitle[] {"C++ Crash Course"};
  Book cPP = proAngular; // (3) 
  cPP.printAddress(3);                                        // 3) Title Address: 0061FEE4
  cPP.set_title(cPPTitle); 
  printf("4) C++ Title = %s \n", cPP.get_title());            // 4) C++ Title = C++ Crash Course
  printf("5) Angular Title = %s \n", proAngular.get_title()); // 5) Angular Title = Pro Angular 6

  char cSharpTitle[] {" C# Study Guide"};
  Book cSharp { 20 };
  cSharp.set_title(cSharpTitle);
  printf("6) C# Title = %s \n", cSharp.get_title());          // 6) C# Title =  C# Study Guide
  cSharp.printAddress(7);                                     // 7) Title Address: 0061FED0
  
  // Using the copy assingment operator
  cSharp = proAngular;  // (4)
  printf("8) C# Title = %s \n", cSharp.get_title());          //  8) C# Title = Pro Angular 6
  char cSharpTitle2[] {"Advanced Pro C#"};
  cSharp.set_title(cSharpTitle2); // (5)
  printf("9) C# Title = %s \n", cSharp.get_title());;          // 9) C# Title = Advanced Pro C#
  printf("10) Angular Title = %s \n", proAngular.get_title()); // 10) Angular Title = Pro Angular 6
  proAngular.printAddress(11);                                 // 11) Title Address: 0061FEFC
}

/**
 Custom copy solves the problem encountered with default-copy.  
 Here the Copy contructor and the copy assignment operator and explictly implemented by the user. 
 
 1) Explicitly declare theat the default copy constructor is acceptable 
 2) Explicitly declare the the default copy assingment is acceptable 
 3) Invokes the Copy constructor implicitly
 4) Invokes the copy Assignment operator implicitly  


 Output 
    1) Angular Title = Pro Angular 6 
    2) Title Address: 0061FEFC 
    3) Title Address: 0061FEE4
    4) C++ Title = C++ Crash Course
    5) Angular Title = Pro Angular 6
    6) C# Title =  C# Study Guide
    7) Title Address: 0061FED0
    8) C# Title = Pro Angular 6
    9) C# Title = Advanced Pro C#
    10) Angular Title = Pro Angular 6
    11) Title Address: 0061FEFC
*/