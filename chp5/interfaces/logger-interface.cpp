#include <cstdio>
#include <stdexcept>

// A pure virtual class - An interface
struct Logger {
  virtual ~Logger() = default;

  virtual void log_transfer(long from , long to, double amount) = 0;
};


struct ConsoleLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[Cons] %ld -> %ld : %f \n", from, to, amount);
  }
};

struct FileLogger : Logger {
  void log_transfer(long from , long to, double amount) override {
    printf("[File] %ld -> %ld :  %f \n", from , to, amount);
  }
};

// Using constructor injection 
struct Bank {
  Bank(Logger& logger): logger { logger } {} // (1)

  void make_transfer(long from, long to, double amount) {
    logger.log_transfer(from , to, amount);
  }

  private: 
    Logger& logger; 
};

// Using property injection 
struct Insurance {
  
  void make_payment(long from, long to, double amount) {
    logger->log_transfer(from, to, amount);
  }
  
  void set_logger(Logger* new_logger) { // (2)
    logger = new_logger;
  }

  private: 
    Logger* logger {};
};

int main() {
  ConsoleLogger consoleLogger {};
  Bank bank { consoleLogger };
  bank.make_transfer(12750, 12755, 1000); // [Cons] 12750 -> 12755 : 1000.000000
  bank.make_transfer(12750, 12756, 1500); // [Cons] 12750 -> 12756 : 1500.000000 

  Insurance insurance;
  insurance.set_logger(&consoleLogger);
  insurance.make_payment(52175, 52178, 2300); // [Cons] 52175 -> 52178 : 2300.000000

  FileLogger fileLogger;
  insurance.set_logger(&fileLogger);
  insurance.make_payment(52175, 52179, 2500); // [File] 52175 -> 52179 :  2500.000000


}
/**
 A class that contain only pure-virtual methods is called a pure-virtual class. 
 In C++, interfaces are always pure-virual classes. 

 1) This approch uses a references to Logger, references cannot be reseated, so the object that logger points to doesn't change 
    for the lifetime of Bank.
 2) This approach uses a pointer instead of a reference. Because pointers can be reseated, you can change Bank's logger 
    whenever you like 
*/