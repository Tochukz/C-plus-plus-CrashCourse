#include <cstdio>

int increaseScore(const int& score) {
  // score += 15; // Error: expression must be modifiable lvalue
  auto& sameScore = const_cast<int&>(score); // (1)
  sameScore += 7;
  return sameScore;
}

short increment(void* count) {
  auto shortCount = static_cast<short*>(count); // (2)
  *shortCount = *shortCount + 1;
  return *shortCount;
}

long charToLong(char* x) {
  auto y = reinterpret_cast<const unsigned long>(x); // (3)
  return y;
}

int main() {
  const int oldScore { 78 };
  const int newScore = increaseScore(oldScore);
  
  printf("Old Score %d \n", oldScore);   // Old Score 78 
  printf("New Score = %d \n", newScore); // New Score = 85 

  int count { 5 };
  short newCount  = increment(&count);
  printf("New Count = %d \n", newCount); // New Count = 6

  char a = '9';
  long b = charToLong(&a);
  printf("a = %c, b = %lu \n", a, b); // a = 9, b = 6422283

}

/**
 Named Conversion Functions 
 Named conversions are languages features that explicitly convert one type into another type:
 1) const_cast() allows you to modify a const object by casting away the const qualifier. It gives you write access to a const object. 
    You can also use const_cast() to add const to an object't type but it is verbose and unnecessary.
 2) static_cast() reverses a well-defined implicit conversion, such as an integer type to another integer type
 3) reinterpret_cast() gives you full control to perform type conversions that are not well defined. 
*/