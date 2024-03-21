#include<iostream>

struct Person {
  std::string m_fullname;

  operator bool(){
    return m_fullname.length() > 0;
  }
};

int main(void){
  Person p;
  std::cout << "Insert the person's name and press enter. Can be blank." << std::endl;
  std::getline(std::cin, p.m_fullname);

  /**
  * !!!
  * Converting Person to bool
  * !!!
  */
  if (p) std::cout << "person is truthy" << std::endl;
  else std::cout << "person is falsey" << std::endl;

  return 0;
}
