#include <cstdio>

struct Element {
  Element* next {};

  void insert_after(Element* new_element) {
    new_element->next = next;
    next = new_element;
  }

  char prefix[2];
  short operating_number;
};

int main() {
  Element element1, element2, element3;

  element1.prefix[0] = 'T';
  element1.prefix[1] = 'K';
  element1.operating_number = 421;
  element1.insert_after(&element2);

  element2.prefix[0] = 'F';
  element2.prefix[1] = 'N';
  element2.operating_number = 2187;
  element2.insert_after(&element3);

  element3.prefix[0] = 'L';
  element3.prefix[1] = 'S';
  element3.operating_number = 005;

  for (Element *cursor = &element1; cursor; cursor = cursor->next) {
    printf("Element %c%c-%d \n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
  }
}
/***
 Output: 
   Element TK-421 
   Element FN-2187 
   Element LS-5    
*/