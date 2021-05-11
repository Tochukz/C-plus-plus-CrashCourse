#include <cstdio>

struct IAccountDatabase {
  virtual ~IAccountDatabase() = default;

  virtual int deposit(int amount) =0;
  
  virtual int withdraw(int amount) =0;
};

struct ILogger {
  virtual ~ILogger() = default;

  virtual void log_transaction(long, double, double) const =0;

  virtual void set_prefix(char*) =0;
};

struct AccountMemory: IAccountDatabase {
  int deposit(int amount) {
    balance += amount;
    return balance;
  }
  
  int withdraw(int amount) {
    balance -= amount;
    return balance;
  }

  private:
    long id;
    int balance {0};
};

struct AccountLogger : ILogger {
  AccountLogger(char* prefix): prefix { prefix } {}

  void set_prefix(char* pfx) {
    prefix = pfx;
  }

  void log_transaction(long account, double amount, double balance) const {
    printf("[%s] Acct%d : %f Balance: %f \n", prefix, account, amount, balance);
  }

  private: 
    char* prefix;
};

struct Bank {
  Bank(IAccountDatabase& account, ILogger* logger): account { account }, logger { logger } {}

  int make_deposit(long to, double amount) {
    int balance = account.deposit(amount);
    char prefix[] {"Credit"};
    logger->set_prefix(prefix);
    logger->log_transaction(to, amount, balance);
    return balance;
  }

  int make_withdrawal(long from, double amount) {
    int balance = account.withdraw(amount);
    char prefix[] {"Debit"};
    logger->set_prefix(prefix);
    logger->log_transaction(from, amount, balance);
    return balance;
  }

  private: 
    IAccountDatabase& account;
    ILogger* logger {};
};

int main() {
  char prefix[] {"Test Log"};
  AccountLogger logger { prefix };
  logger.log_transaction(120055, 2500, 2500); // [Test Log] Acct120055 : 2500.000000 Balance: 2500.000000 

  AccountMemory account;
  Bank bank { account, &logger };
  bank.make_deposit(12750, 100'000);   // [Credit] Acct12750 : 100000.000000 Balance: 100000.000000 
  bank.make_deposit(12750, 150'000);   // [Credit] Acct12750 : 150000.000000 Balance: 250000.000000
  bank.make_withdrawal(12750, 25'000); // [Debit] Acct12750 : 25000.000000 Balance: 225000.000000
}