#include <cstdio>
#include <utility>

template<typename T>
struct SimpleUniquePointer {
  SimpleUniquePointer() = default; // (1)

  SimpleUniquePointer(T* pointer) : pointer { pointer } {

  }

  ~SimpleUniquePointer() {
    if (pointer) {
        delete pointer;
    }
  }

  SimpleUniquePointer(const SimpleUniquePointer&) = delete;

  SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

  SimpleUniquePointer(SimpleUniquePointer&& other) noexcept : pointer { other.pointer }{
    other.pointer = nullptr;
  }

  SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
    if (pointer) {
      delete pointer;
    }
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }

  T* get() {
      return pointer;
  }
  
  private: 
    T* pointer;
};

struct Tracer {
  Tracer(const char* name): name { name } {
    printf("%s Contruct \n", name);
  }

  ~Tracer() {
    printf("%s Destruct \n", name);
  }

  private: 
    const char* name;
};

void consumer(SimpleUniquePointer<Tracer> cosumerPtr) {
  printf("(consumer) cosumerPtr: 0x%p \n", cosumerPtr.get());
}

int main() {
  auto pointerA = SimpleUniquePointer<Tracer> { new Tracer { "PointerA"} };
  printf("(main) pointerA: 0x%p \n", pointerA.get());
  consumer(std::move(pointerA));
  printf("(main) pointerA: 0x%p \n", pointerA.get());
}

/**
  1) You need default if you want both a default constructor and a non-default constructor
   
  With SimpleUniquePointer you won't leak a dynamically allocated object
  Output 
    PointerA Contruct 
    (main) pointerA: 0x00B320D8       
    (consumer) cosumerPtr: 0x00B320D8 
    PointerA Destruct 
    (main) pointerA: 0x00000000  

*/