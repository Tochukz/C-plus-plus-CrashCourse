#include <cstdio>

template<typename X, typename Y, typename Z>
struct FirstTemplateClass {
  Y sum(X&);

  private: 
    Z* obj;
};

template<typename A, typename B, typename C>
C first_template_func(A& arg1, const B* arg2) {
    
}

int main() {
  printf("Hello Template!");
} 