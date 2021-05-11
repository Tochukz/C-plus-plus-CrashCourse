#include <cstdio>
#include <stdexcept>

struct ConsoleLogger {
  void log_transfer(long from, long to, double amount) {
    printf("[Cons] %ld -> %ld : %f \n", from , to, amount);
  }
};

struct FileLogger {
  void log_transfer(long from, long to, double amount) {
    printf("[file] %ld -> %ld : %f \n", from , to, amount);
  }
};

enum LoggerType {
  Console,
  File
};

struct Bank {
  Bank(): loggerType { LoggerType::Console } {}

  void make_transfer(long from , long to, double amount) {
    switch(loggerType) {
      case LoggerType::Console: {
        consoleLogger.log_transfer(from, to, amount);
        break;
      }
      case LoggerType::File: {
        fileLogger.log_transfer(from, to, amount);
        break;
      }
      default: { 
        std::logic_error("Unknown logger type encountered!");
        break;
      }
    }
  }

  void set_logger(LoggerType type) {
    loggerType = type;
  }

  private: 
    LoggerType loggerType;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
};

int main() {
  Bank bank;
  bank.make_transfer(12750, 12755, 1500); // [Cons] 12750 -> 12755 : 1500.000000
  bank.make_transfer(12750, 12756, 1700); // [Cons] 12750 -> 12756 : 1700.000000 
  bank.set_logger(LoggerType::File);
  bank.make_transfer(12750, 12757, 2300); // [file] 12750 -> 12757 : 2300.000000 
}