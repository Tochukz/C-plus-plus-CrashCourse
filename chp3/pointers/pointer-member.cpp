#include <cstdio>  

struct Product {
  void set_price(int pr) {
    price = pr;
  }
  
  int get_price() {
    return price;
  }

  private: int price { 1999 };
};

int main() {
  Product phone;
  Product* phone_ptr = &phone;
  phone_ptr->set_price(2900);

  printf("Address of phone = %p \n", phone_ptr);              // Address of phone = 0061FF08 
  printf("Price pf phone = %d \n", phone_ptr->get_price());   // Price pf phone = 2900 
  printf("Price of phone = %d \n", (*phone_ptr).get_price()); // Price of phone = 2900
}

/**
 member-to-pointer operator is -> 
*/