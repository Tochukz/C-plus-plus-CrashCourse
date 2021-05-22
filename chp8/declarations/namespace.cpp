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
  struct User {
    User(char* name): name { name } {}
    
    void printName() {
      printf("Name = %s\n", name);
    }

    private: 
      const char* name;
  };
}

int main() {
  char username1[] {"Tochukwu"};
  App::Models::User user1 = App::Models::User { username1 };
  user1.printName(); // Name = Tochukwu

  char username2[] {"Lynton"};
  Root::Models::User user2 = Root::Models::User { username2 };
  user2.printName(); // Name = Lynton
}  

/**
 1) Defining a nested namespace
 2) Defining a nested namespace using scope resolution operator 
*/