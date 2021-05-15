#include <cstdio>
#include <stdexcept>
#include <type_traits>
#include <cstddef>

struct User {
  User() = default;
  User(const User&) = delete;  
};

template<typename T>
  requires std::is_copy_constructible<T>::value
T get_copy(T pointer) {
  if (!pointer) {
    throw std::runtime_error{ "Null-pointer dereference" };
  }
  return *pointer;
}


int main() {
  User user;
  User* user_ptr = &user;
  auto user_copy = get_copy(user);
}

/**
 // Todo
 * Page [172]
 This source code refuse to compile return back later

 You can embed required expressions directly into a template. 
 This is called an "Ad Hoc Requires Expression"
*/