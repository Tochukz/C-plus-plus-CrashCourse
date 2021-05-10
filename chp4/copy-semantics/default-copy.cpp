#include <cstdio>
#include <cstring>

struct Book { 
  Book(const Book&) = default; // (1)

  Book& operator=(const Book&) = default; //(2)

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
  printf("5) Angular Title = %s \n", proAngular.get_title()); // 5) Angular Title = C++ Crash Course

  char cSharpTitle[] {" C# Study Guide"};
  Book cSharp { 20 };
  cSharp.set_title(cSharpTitle);
  printf("6) C# Title = %s \n", cSharp.get_title());          // 6) C# Title =  C# Study Guide
  cSharp.printAddress(7);                                     // 7) Title Address: 0061FED0
  
  // Using the copy assingment operator
  cSharp = proAngular;  // (4)
  printf("8) C# Title = %s \n", cSharp.get_title());          // 8) C# Title = C++ Crash Course
  char cSharpTitle2[] {"Advanced Pro C#"};
  cSharp.set_title(cSharpTitle2); // (5)
  printf("9) C# Title = %s \n", cSharp.get_title());;          // 9) C# Title = Advanced Pro C#
  printf("10) Angular Title = %s \n", proAngular.get_title()); // 10) Angular Title = Advanced Pro C#
  proAngular.printAddress(11);                                 // 11) Title Address: 0061FEFC
}

/**
 Any time a class manages a resource, you must be extremely careful with default copy semantics; they are likely to be wrong. 
 Best practice dictates that you explicitly declare that default copy assignment and copy construction are acceptable for such classes using the default keyword.  
 
 1) Explicitly declare theat the default copy constructor is acceptable 
 2) Explicitly declare the the default copy assingment is acceptable 
 3) Invokes the Copy constructor implicitly
 4) Invokes the copy Assignment operator implicitly  

 Default Copy is not reliable as can be seen from the demonstration: 
  * When call set_title() for the cPP object, the title of the proAgular object also changes. This can be seen by comparing 
    print (1), (4) and (5). 
    This is as a result of code (3)
  * Similarly when you call set_title() on line (5), it results in a change in the title of proAgular also. This can be seen by comparing 
    print (8), (9) and (10). 
    This is as a result of code (4) 
  * So even though their addresses may differe their data seems to be coming from the same source


 Output: 
    1) Angular Title = Pro Angular 6 
    2) Title Address: 0061FEFC 
    3) Title Address: 0061FEE4
    4) C++ Title = C++ Crash Course
    5) Angular Title = C++ Crash Course
    6) C# Title =  C# Study Guide
    7) Title Address: 0061FED0
    8) C# Title = C++ Crash Course
    9) C# Title = Advanced Pro C#
    10) Angular Title = Advanced Pro C#
    11) Title Address: 0061FEFC
*/