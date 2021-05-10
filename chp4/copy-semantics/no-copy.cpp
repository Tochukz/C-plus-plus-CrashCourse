#include <cstdio>

struct Book {
  Book(size_t title_len) {
    title = new char[title_len];
    title[0] = 0;  
  }
  
  // The Copy Constructor
  Book(const Book&) = delete;

  // The Copy Assignment Operator
  Book& operator=(const Book&)  = delete;

  ~Book() {
    delete[] title;
  }

  private: 
    char* title;;
};

int main() {
  Book learnReact { 30 };
  
  // Book proVue { learnReact }; // (1) 

  Book proASP { 35 };
  // proASP = learnReact; // (2)

}

/**
 Some classes simply cannot or should not be copied - for example, if your class manages a file or if it represents a mutual exclusive 
 lock for concurrent programming. You can suppress the compiler from generating a cop constructor and a copy assignment operator using 
 the delete keyword. 

 1) Error: Because the Copy constructor is marked as delete
 2) Error: Beause the Copy Assignment Operator is marked as delete
*/