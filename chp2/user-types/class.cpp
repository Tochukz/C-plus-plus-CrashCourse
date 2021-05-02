#include <cstdio>

/** Fully featured class */
struct Calender {
  int year;

  void add_year() {
    year++;
  }

  bool set_month(int mth) {
    if (mth > 0 && mth <= 12) {
       month = mth;
       return true;
    }
    return false;   
  }

  int get_month() {
    return month;
  }

  private: int month;
};

/** Using the class keyword instead of struct*/
class Clock {
  public: int hour;

  int minute;

  void set_minute(int min) {
    if (min >= 0 && min <= 60) {
      minute = min;
    }
  }

  int get_minute() {
    return minute;
  }

};

int main() {
  Calender calender;
  calender.year = 2019;

  Clock clock;
  clock.hour = 16;

  calender.add_year();
  printf("Year: %d \n", calender.year); // Year: 2020 

  calender.add_year();
  printf("Year: %d \n", calender.year); // Year: 2021

  clock.set_minute(45);
  printf("Hour: %d \n", clock.hour);     // Hour: 16
  printf("Minute: %d \n", clock.minute); // Minute: 45
}

/**
 You can replace the struct keyword with class keyword. 
 struct declares members public by default while
 class declares members private by default? No, all members are public by default
 The public members should be listed before private members
*/