#include<iostream>

/*
  È molto interessante la differenza tra il caso 2 ed il caso 3.
  Nel caso due avviene memory leak, nel caso 3 no.

  Perché??
*/

struct obj{
  int m_value;

  obj(int value): m_value(value) {
    std::cout << "created obj with value " << m_value << std::endl;
  }

  ~obj() {
    std::cout << "deleted obj with value " << m_value << std::endl;
  }

  obj& operator+(const obj& other){
    obj* res = new obj{m_value + other.m_value};
    return *res;
  }

  friend std::ostream& operator<<(std::ostream& os, const obj a){
    os << a.m_value;
    return os;
  }
};

int main(void){
  obj a{5};
  obj b{8};

  // CASE 1.
  // with the block, the object is deleted when exiting from the block, immediately
  /*
  std::cout << "\n\nCASE #1\n\n" << std::endl;

  { // block start

    obj c = a + b;
    std::cout << "new value: " << c.m_value << std::endl;
  } // block end

  std::cout << "\n\nEND CASE #1\n\n" << std::endl;
  */

  // CASE 2
  // Si ha un memory leak.
  // /*
  std::cout << "\n\nCASE #2\n\n" << std::endl;
  {
    std::cout << (a + b).m_value << std::endl;
  }
  std::cout << "\n\nEND CASE #2\n\n" << std::endl;
  // */

  // CASE 3
  // Non si hanno memory leak.
  // Output identico al caso del blocco.
  /*
    std::cout << "\n\nCASE #3\n\n" << std::endl;
    std::cout << a + b << std::endl;
    std::cout << "\n\nEND CASE #3\n\n" << std::endl;
  */
 
  // CASE 4: create a non-used object inside a block:
  // { obj c = a + b; }

  return 0;
}
