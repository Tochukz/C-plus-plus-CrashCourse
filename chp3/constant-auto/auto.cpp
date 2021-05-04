#include <iostream>


int main() {
  auto year { 2021 };
  auto& year_ref = year;
  const auto& year_cref = year;
  auto* year_ptr = &year;
  const auto* year_cptr = &year;

  printf("%d, %d, %d \n", year, year_ref, year_cref);   // 2021, 2021, 2021
  printf("%d, %d, %d \n", year, *year_ptr, *year_cptr); // 2021, 2021, 2021

  std::string names[] {"James", "Maxwel", "Peter"};
  for(auto name : names) {
    std::cout << name << std::endl;
  }
}