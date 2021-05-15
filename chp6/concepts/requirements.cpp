#include <cstdio>

template<typename T, typename U>
concept bool my_comparable() {
  return requires(T t, U u) {
    {t == u} -> bool;
    {u == t} -> bool;
    {t != u} -> bool;
    {u != t} -> bool;
  };
}

int main() {

}

/**
 To compile the with concept use the -fconcepts flag 

 > c++ requirements.cpp -o ../bin/requirements -fconcepts
*/ 