#include <cstdio>

namespace App { // (1)
  namespace Models {
    struct User {
      User(char* name): name { name } {}
      
      void printName() {
        printf("Name = %s\n", name);
      }

      private: 
        const char* name;
    }; 
  }
}

namespace Root::Models { // (2)
  using App::Models::User; // (4)

  struct Student {
    Student(char* name) : user { User { name }} {}
    
    void printName() {
      user.printName();
    }

    private: 
      User user;
  };
}

using namespace Root::Models; // (5)

int main() {
  using App::Models::User; // (3)

  char username1[] {"Tochukwu"};
  User user1 = User { username1 };
  user1.printName(); // Name = Tochukwu

  char username2[] {"Kelvin"};
  Student student { username2 }; 
  student.printName(); // N 
}  

/**
 1) Defining a nested namespace
 2) Defining a nested namespace using scope resolution operator 
 3) Using Directive in a block scope
 4) using directive in a namespace scope
 5) using namespace statement in the global scope imports multiple symbold into the global namesapce

 Usually, it's a bad idea to have too many using namesapce directive appear in a single translation unit. 
*/