#define CATCH_CONFIG_MAIN // (1)
#include "catch.hpp"
#include <stdexcept>
#include <cstdio>

unsigned int factorial(unsigned int number) {
  return number > 1 ? number * factorial(number-1) : 1;
}

void make_error() {
  throw std::runtime_error {"a contrived exception"};
}

double multiply(double x, double y) {
  return x * y;
}

struct Arithmetic {
  Arithmetic(double num): number { num } {
    printf("Constructing Arithmetic \n");
  }

  double add(double x) {
    number += x;
    return number;
  }

  double minus(double x) {
    number -= x;
    return number;
  }

  double times(double x) {
    number *= x;
    return number;
  }

  double divide(double x) {
    number /= x;
    return number;
  }

  private: 
    double number;
};

TEST_CASE("Factorials are computed", "[factorial]")  { // (2)
  REQUIRE(factorial(6) == 720); // (3)
  REQUIRE(factorial(4) == 24);    
  REQUIRE(factorial(0) == 1);
}

TEST_CASE("Exceptions are thrown", "[make_error]") {
  REQUIRE_THROWS(make_error());
  CHECK_THROWS_AS(make_error(), std::runtime_error);
}

TEST_CASE("Floting point approximation", "[multiply]") {
  REQUIRE(multiply(1.95, 3.12) == Approx(6.084)); // (4)
}

TEST_CASE("Arithmetic TestSuite", "[Arithmetic]") { // (5)
  // Test setup
  Arithmetic arithmetic { 10 };

  SECTION("add") {
    REQUIRE(arithmetic.add(5) == 15);    
  }

  SECTION("minus") {
    REQUIRE(arithmetic.minus(2) == 8);
  }

  SECTION("times") {
    REQUIRE(arithmetic.times(8) == 80);
  }

  SECTION("divide") {
    REQUIRE(arithmetic.divide(3) == Approx(3.33).margin(0.004));
  }
}

/**
 1) This tells Catch to provide a main() - only do this in one cpp file 
 2) The TEST_CASE Macro is used to introduce a test case 
 3) The REQUIRE Macro is used to write test assertions. 
    Other assertion macros include REQUIRE_FALSE, CHECK, CHECK_FALSE, REQUIRE_THROWS etc
 4) Using Catch2's  Approx class to handle floating point numbers comparision
 5) A test suite having a test setup
    Each SECTION will be prepended with a copy of the setup. 
    So a change in the state of the Arithmetic Object by one section does not affect the other, since each have their own Arithmetic object

 Macros are a piece of code in a program which is given some name. 
 Whenever this name is encountered by the compiler the compiler replaces the name with the actual piece of code. 
 The ‘#define’ directive is used to define a macro.
*/