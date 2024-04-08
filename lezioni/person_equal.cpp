#include<iostream>

struct Person {
  std::string fullname;
  int age;
};


std::ostream& operator<<(std::ostream& os, const Person& p){
  os << "fullname: " << p.fullname << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Person& p){
  std::cout << "operator>>" << std::endl;
  std::cout << "name: ";
  std::string fullname;
  std::cin >> fullname;
  p.fullname = fullname;
  return is;
}

int main(void){
  Person p;
  std::cin >> p;

  std::cout << p;

  return 0;
}
