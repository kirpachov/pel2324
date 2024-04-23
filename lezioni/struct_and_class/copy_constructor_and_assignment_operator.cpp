#include<iostream>

struct obj {
  int m_val;

  obj(): m_val(0) {
    std::cout << "default constructor" << std::endl;
  }

  obj(const int val): m_val(val) {
    std::cout << "copy constructor" << std::endl;
  }

  obj operator=(obj const& other) {
    std::cout << "operator=" << std::endl;

    return *this;
  }
};

int main(){
  obj a{5};
  obj b = a;
  // obj c;
  // c = a;

  return 0;
}
