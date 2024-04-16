#include<iostream>

struct obj{
  int m_value;

  obj(int value): m_value(value) {
    std::cout << "created obj with value " << m_value << std::endl;
  }

  ~obj() {
    std::cout << "deleted obj with value " << m_value << std::endl;
  }

  // CASE 0: returning reference to object. memory leak.
  // /*
  obj& operator+(const obj& other) const {
    obj* res = new obj{m_value + other.m_value};
    return *res;
  }
  // */

  // CASE 1: returning object, no memory leak.
  /*
  obj operator+(const obj& other) const {
    return obj{m_value + other.m_value};
  }
  */

  // CASE 2: returning pointer to object. memory leak.
  /*
  obj* operator+(const obj& other) const {
      return new obj{m_value + other.m_value};
  }
  */

  friend std::ostream& operator<<(std::ostream& os, const obj a){
    os << a.m_value;
    return os;
  }
};

int main(void){
  obj a{5};
  obj b{8};

  std::cout << "\n\nCASE #1\n\n" << std::endl;
  std::cout << (a + b).m_value << std::endl; // Distructor never called. Why???
  // std::cout << (a + b) << std::endl;

  std::cout << "\n\nEND CASE #1\n\n" << std::endl;

  return 0;
}
