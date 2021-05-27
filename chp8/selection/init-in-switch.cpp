#include <cstdio>

enum class Color {
  Blue, 
  Yellow, 
  Red,
};

struct Message {
  const char* message;
  Color color;
};

Message get_message(const char* msg) {
  return Message {msg, Color::Blue};
}

int main() {
  const char* description;
  switch(const auto message = get_message("You got Cert"); message.color) {
    case Color::Blue: {
      description = "information message";
      break;
    }
    case Color::Yellow: {
      description = "warning message";
      break;
    }
    case Color::Red: {
      description = "error message";
      break;
    }
    default : {
      description = "unknown message type";
    }
  }
  
  printf("The message is %s type \n", description);
}

/**
 Output:
   The message is information message type 

 NB: init-statement in selection is only available in C++17 
 use the -std=c++17 flag to compile the code 

 c++ .\init-in-switch.cpp -o ..\bin\init-in-switch -std=c++17
*/