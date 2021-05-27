#include <cstdio>

namespace App::Models {
  struct User  {
    User(size_t user_id): user_id { user_id } {}

    void print_name(const char* name) const {
      printf("Name = %s, UserID = %d", name, user_id);
    }

    private: 
      size_t user_id;
  };
}


namespace App {

  namespace Controllers {

    using App::Models::User;
    struct UserController {
      User get(size_t user_id) {
        User user { user_id };
        return user;
      }
    };
  }
}

// (1)
using UserCtrl = App::Controllers::UserController;
using User = App::Models::User;
using String = const char[24];

int main() {
  UserCtrl userCtrl;
  User user { userCtrl.get(1228) };
  String name {"Johnny"};
  user.print_name(name); //Name = Johnny, UserID = 1228

}

/**
 1) Usign type alias

 Type aliases can appear in any scope — block, class, or namespace.
*/