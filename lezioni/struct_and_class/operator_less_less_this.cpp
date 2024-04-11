#include<iostream>

/**
  NON COMPILA.

  MORALE: operator<< non sa cos'è this, nè conosce m_value.
*/

struct obj {
  obj(const int a): m_value(a) {}

  int m_value;

  friend std::ostream& operator<<(std::ostream& os, obj& a){
    std::cout << "this is " << this;
    return os;
  }
}

int main(void){
  obj a{2};

  std::cout << a << std::endl;

  return 0;
}
