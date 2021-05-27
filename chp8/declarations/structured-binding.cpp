#include <cstdio>

struct TextFile {
  bool  success;
  const char* contents;
  size_t n_bytes;
};

TextFile read_text_file(const char* path) {
  const static char contents[] { "Sometimes the goat is you."};
  return TextFile {true, contents, sizeof(contents)};
}

int main() {
  const auto [success, contents, length] = read_text_file("README.txt"); // (1)
  if (success) {
    printf("Read %zd bytes: %s\n", length, contents);
  } else {
    printf("Failed to open README.txt");
  }
}

/**
 Structured binding  enables you to unpack objects into their constituent elements.  

 1) strcutured binding declaration 

 Output:
   Read 27 bytes: Sometimes the goat is you.

 NB: Structured binding is only available in C++17
 Use the -std=c++17 flag to compile the code 
 
 > c++ .\structured-binding.cpp -o ..\bin\structured-binding -std=c++17
*/