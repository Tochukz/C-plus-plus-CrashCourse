#include <cstdio> 

enum class Operation {
  Add, 
  Subtract, 
  Multiple, 
  Divide
};

struct Calculator {
  Operation operation {};

  Calculator(Operation action) {
    operation =  action ;
  }

  int calculate(int a, int b) {
    switch (operation)
    {
      case Operation::Add: 
        return a + b;
      case Operation::Subtract:
        return a - b;
      case Operation::Multiple: 
        return a * b;
      case Operation::Divide: 
        return a / b;
      default: 
        printf("Error: operation not implemented!");
        return 0;
    }
  }
};

int main() {
  int a { 12 };
  int b { 6 };

  Calculator plusCalculator { Operation::Add };
  int aPlusb { plusCalculator.calculate(a, b) };

  Calculator subtractCalculator { Operation::Subtract };
  int aMinusb { subtractCalculator.calculate(a, b)};

  Calculator mutiplyCalculator { Operation::Multiple };
  int aTimesb { mutiplyCalculator.calculate(a, b)};

  Calculator divideCalculator { Operation::Divide };
  int aDivideb { divideCalculator.calculate(a, b) };

  printf("a + b = %d \n", aPlusb);   // a + b = 18 
  printf("a - b = %d \n", aMinusb);  // a - b = 6 
  printf("a * b = %d \n", aTimesb);  // a * b = 72
  printf("a / b = %d \n", aDivideb); // a / b = 2
}