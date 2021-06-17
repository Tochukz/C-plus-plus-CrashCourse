#include <cstdio>
#include <exception>

void run_test(void(*unit_test)(), const char* name){
  try {
    unit_test();
    printf("[+] Test %s successful.\n", name);
  } catch(const std::exception& e) {
    printf("[-] Test failure in %s. %s, \n", name, e.what());
  }
}

/**  
 A test harness is code that executes unit tests 
*/