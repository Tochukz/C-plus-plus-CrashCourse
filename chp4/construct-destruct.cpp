#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size): max_size { max_size }, length { } {
    if (max_size == 0) {
      throw std::runtime_error {" max_size must be at least 1"};
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }

  ~SimpleString() {
    delete[] buffer;
  }

  void print(const char* tag) const {
    printf("%s %s", tag, buffer);
  }

  bool append_line(const char* x) {
    const size_t x_len = strlen(x);
    if (x_len + length + 2 > max_size) {
      return false;
    }
    std::strncpy(buffer + length, x, max_size - length); // (2)
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }  

  private: 
    size_t max_size;
    size_t length;
    char* buffer;
};

int main() {
  SimpleString simpleStr { 115 };
  simpleStr.append_line("Cape town is beautiful!");
  simpleStr.append_line("I love it here!");
  simpleStr.print("A: ");
  simpleStr.append_line("I will visit an American's city someday!");
  simpleStr.append_line("sooner or later.");
  simpleStr.print("B: ");

  if (!simpleStr.append_line("The end of the city story!")) {
    printf("Maximum string length was exceeeded!");
  }
  
}

/**
  1) max_size is a size_t, it is unsigned and cannot b negative, so you don't need to check for theis bigus condition
  2) Use strncpy() very carefuly. It is too easy to forget the nullterminator in the source string or not allocate enough space in the destination string.
     Both errors will cause undefined behavior. There is a safer alternative to strncpy()

  Because you've paired the allocation and deallocation of buffer with the constructor and destructor of SimpleString, you'll never leak the storage.  
  This pattern is called resource acquisition is initialiation (RAII) or constructor acquires, destructor releases (CADRe).

  The SimpleString class still has an implicitly defined copy constructor. Although it might never leak the storage, it will potentially double free if copy. 
  Learn more about copy constructors... 

  Output: 
    A:  Cape town is beautiful!
    I love it here!
    B:  Cape town is beautiful!
    I love it here!
    I will visit an American's city someday!
    sooner or later.
    Maximum string length was exceeeded!
*/