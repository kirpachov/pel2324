#include<iostream>

/*
  DOMANDA: in un contesto const, posso chiamare metodi non-const?

  No. Solo metodi 'const' possono essere chiamati. Vedi metodo 'const_context'.
*/

struct obj {
  void const_method() const {
    std::cout << "const_method called" << std::endl;
  }

  void non_const_method() {
    std::cout << "non_const_method called" << std::endl;
  }
};

void const_context(const obj& a){
  std::cout << "BEGIN const_context" << std::endl;
  a.const_method();
  // a.non_const_method(); // <----- THE ONLY WRONG LINE
  std::cout << "END const_context" << std::endl;
}

void non_const_context(obj& a){
  std::cout << "BEGIN non_const_context" << std::endl;
  a.const_method();
  a.non_const_method();
  std::cout << "END non_const_context" << std::endl;
}


int main(){
  obj local;

  const_context(local);

  non_const_context(local);

  std::cout << "BEGIN main context" << std::endl;
  local.const_method();
  local.non_const_method();
  std::cout << "END main context" << std::endl;

  return 0;
}
