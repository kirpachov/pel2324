#include<iostream>

/**
  Domanda: fare la delete di un puntatore lo imposta a nullptr?

  Risposta: No.
*/

struct obj {
  int m_val;

  obj(const int v): m_val(v){
    std::cout << "costructor with value" << m_val;
  }

  ~obj(){
    std::cout << "destructor" << std::endl;
  }
};

int main(){

  obj* a = new obj{15};
  std::cout << "a is (" << a << ")" << std::endl;

  std::cout << "going to delete a" << std::endl;
  delete a;

  std::cout << "a is (" << a << ")" << std::endl;
  
  return 0;
}
