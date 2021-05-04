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

void add_year(Calender& calender) { // (1)
  calender.set_year(calender.get_year() + 1); 
}

int main() {
  int score = 85;
  int& score_ref = score; // declare scoreRef a refernece to score
  printf("score = %d, score_ref = %d \n", score, score_ref); // score = 85, score_ref = 85

  int new_score = 96;
  score_ref = new_score;
  printf("score = %d, score_ref = %d, new_score = %d \n", score, score_ref, new_score); // score = 96, score_ref = 96, new_score = 96 

  Calender calender;
  printf("Year %d \n", calender.get_year()); // Year 2020 
  
  add_year(calender); // (2)
  printf("Year %d \n", calender.get_year()); // Year 2021 
}

/**
 References are safer, more convenient version of pointers. 
 References canno be assigned to null (easily) and they cannot be reseated (or reassigned) 

 1) The add_year function requires a reference to Calender as it only argument
 2) calender is implicitly passed by reference because of the reference operator on the function signature
*/