#include <cstdio>  
#include <cstring>

struct Product {
  Product(size_t max_size): max_size { max_size } {
    name = new char[max_size];
    name[0] = 0;
  }
  
  // The copy constructor
  Product(const Product& exitingP): max_size { exitingP.max_size }  { // (1)
    size_t descriptionLen = 30; 
    description = new char[descriptionLen];
    name = new char[ exitingP.max_size];
    std::strncpy(description, exitingP.description, descriptionLen); 
    std::strncpy(name, exitingP.name, exitingP.max_size); 
   
    printf("Product copied! \n");
  }
  
  // The copy assignment operator 
  Product& operator=(const Product& other) { // (2)
    if (this == &other) {
      return *this;
    }
    size_t descriptionLen = 30; 
    const auto new_name = new char[other.max_size];
    const auto new_description = new char[descriptionLen];
    delete[] name;
    delete[] description;
    
    name = new_name;
    description = new_description;
    max_size = other.max_size;
    strncpy(name, other.name, max_size);
    strncpy(description, other.description, descriptionLen);
    printf("Product Assigned! \n");
    return *this;
  } 

  void set_name(char* nm) {   
    name = nm;
  }

  char* get_name() {
    return name;
  }

  ~Product() {
    delete[] name;
  }

  char* description;
  private: 
    size_t max_size;
    char* name;

};

void change_description(Product product) { // (7)
  // 
}


int main() {
  char laptopName[] { "Toshiba" };
  char laptopDescription[] {"A 2.3Ghz laptop"};
  Product laptop { 10 };
  laptop.set_name(laptopName);
  laptop.description = laptopDescription;

  char monitorName[] { "Dell"};
  char monitorDescription[] {"A high resolution monitor"};  
  Product monitor = laptop; // Product copied! (3)
  monitor.set_name(monitorName);
  monitor.description = monitorDescription;

  char driveName[] {"Bluegate"};
  char driveDescription[] {"A 1 TaraByte Drive"};
  Product drive { 20 };
  drive.set_name(driveName);
  drive.description = driveDescription;

  drive = laptop; // Product Assigned! (4)

  Product phone { laptop }; // Product copied! (5)

  printf("Laptop name = %s \n", laptop.get_name());   // Laptop name = Toshiba 
  printf("Monitor name = %s \n", monitor.get_name()); // Monitor name = Dell     
  printf("Drive name = %s \n", drive.get_name());     // Drive name = Toshiba
  printf("Phone name = %s \n", phone.get_name());     // Phone name = Toshiba

  printf("Laptop Description: %s \n", laptop.description);  // Laptop Description: A 2.3Ghz laptop
  printf("Monito Description: %s \n", monitor.description); // Monito Description: A high resolution monitor
  printf("Drive description = %s \n", drive.description);   // Drive description = A 2.3Ghz laptop
  printf("Phone Description: %s \n", phone.description);    // Phone Description: A 2.3Ghz laptop

  char phoneName[] {"Samsung"};
  char phoneDescription[] {"A 6 Inches Smartphone"};
  phone.set_name(phoneName);
  phone.description = phoneDescription;
  printf("Update Phone name = %s \n", phone.get_name());        // Update Phone name = Samsung
  printf("Update Phone Description: %s \n", phone.description); // Update Phone Description: A 6 Inches Smartphone

  change_description(phone); // Product copied! (6)
}

/***
  1) Implementation of a copy constructor
  2) Implementation of a copy assignment operator
  3) The copy constructor is invoked implicitly
  4) The Copy constructor is not invoked but the copy assignment Operator is invoked. 
  5) Initialization of a new object from an existing object using the copy constructor  
  6) The copy constructor in invoked when the product object is passed  to the change_description function by value 
  7) Product object is accepted by value
*/ 