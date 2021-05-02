#include <cstdio>

struct Computer {
  int ram;

  Computer(int rm) {
   ram = rm;
  } 

  void set_ram(int rm) {
    ram = rm;
  }

  int get_ram() {
    return ram;
  }
};


int main() {
  Computer computer { 1024 };
  
  printf("RAM = %d \n", computer.ram);       // RAM = 1024

  computer.set_ram(2048);
  printf("RAM = %d \n", computer.get_ram()); // RAM = 2048 
  
}