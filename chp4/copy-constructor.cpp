#include <cstdio>  
#include <cstring>

struct Product {
  Product(size_t max_size): max_size { max_size } {
    name = new char[max_size];
    name[0] = 0;
  }
  
  // A copy constructor
  Product(const Product& exitingP): max_size { exitingP.max_size }  { // (1)
    size_t descriptionLen { sizeof(exitingP.description)/sizeof(char)};
    description = new char[descriptionLen];
    name = new char[ exitingP.max_size];
    std::strncpy(description, exitingP.description, descriptionLen); 
    std::strncpy(name, exitingP.name, exitingP.max_size); 
   
    printf("Product copied! \n");
  }

  // Acopy assignment operator
  Product& operator=(const Product& other) {
    if (this == &other) {
      return *this;
    }
    const auto new_name = new char[other.max_size];
    delete[] name;
    
    name = new_name;
    max_size = other.max_size;
    strcpy_s(name, max_size, other.max_size);
    return *this;
  }

  void set_name(char* nm) {   
    name = nm;
  }

  char* get_name() {
    return name;
  }

  char* description;
  private: 
    size_t max_size;
    char* name;

};

void change_description(Product product) { // (6)
  char newDescription[] {"A random product description"};
  product.description = newDescription;
}


int main() {
  char laptopName[] { "Toshiba" };
  char laptopDescription[] {"A 2.3Ghz laptop"};
  Product laptop { 10 };
  laptop.set_name(laptopName);
  laptop.description = laptopDescription;

  char monitorName[] { "Dell"};
  char monitorDescription[] {"A high resolution monitor"};  
  Product monitor = laptop; // (2)
  monitor.set_name(monitorName);
  monitor.description = monitorDescription;

  char driveName[] {"Bluegate"};
  char driveDescription[] {"A 1 TaraByte Drive"};
  Product drive { 20 };
  drive.set_name(driveName);
  drive.description = driveDescription;

  drive = laptop; // (3)

  Product phone { laptop }; // (4)

  printf("Laptop name = %s \n", laptop.get_name());   // Laptop name = Toshiba 
  printf("Monitor name = %s \n", monitor.get_name()); // Monitor name = Dell     
  printf("Drive name = %s \n", drive.get_name());     // Drive name = Toshiba
  printf("Phone name = %s \n", phone.get_name());     // Phone name = Toshiba

  printf("Laptop Description: %s \n", laptop.description);  // Laptop Description: A 2.3Ghz laptop
  printf("Monito Description: %s \n", monitor.description); // Monito Description: A high resolution monitor
  printf("Drive description = %s \n", drive.description);   // Drive description = A 2.3Ghz laptop
  printf("Phone Description: %s \n", phone.description);    // Phone Description: A 2.└

  char phoneName[] {"Samsung"};
  char phoneDescription[] {"A 6 Inches Smartphone"};
  phone.set_name(phoneName);
  phone.description = phoneDescription;
  printf("Update Phone name = %s \n", phone.get_name());        // Update Phone name = Samsung
  printf("Update Phone Description: %s \n", phone.description); // Update Phone Description: A 6 Inches Smartphone

  change_description(phone); // (5)
}

/***
  1) Implementation of a copy constructor  
  2) The Copy constructor is invoked implicitly
  3) Does not trigger the Copy constructor
  4) Initialization of a new object from an existing object using the copy constructor  
  5) The copy constructor in invoked when the product object is passed  to the change_description function by value 
  6) Product object is accepted by value
*/ 