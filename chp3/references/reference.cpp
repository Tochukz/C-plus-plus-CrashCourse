#include <cstdio>

struct Calender {
  void set_year(int yr) {
    year = yr;
  }

  int get_year() {
    return year;
  }

  private: int year { 2020 };
};

void add_year(Calender& calender) {
  calender.set_year(calender.get_year() + 1); 
}

int main() {
  Calender calender;
  printf("Year %d \n", calender.get_year()); // Year 2020 
  
  add_year(calender); // calender is implicitly passed by reference 
  printf("Year %d \n", calender.get_year()); // Year 2021 
}

/**
 References are safer, more convenient version of pointers. 
 References canno be assigned to null (easily) and they cannot be reseated (or reassigned) 
*/