#include<iostream>

struct Person {
  std::string m_fullname;

  void operator<<(std::istream& is){
    std::cout << "Inser user fullname and press enter. Can be blank." << std::endl;
    std::getline(is, m_fullname);
    std::cout << "User's name: '" << m_fullname << "'" << std::endl;
  }

};

int main(void){
  Person p;

  /*
    La prima riga funziona e ha senso che funzioni:
    chiamiamo il metodo "<<" sull'oggetto di tipo "Person",
    che prende in input uno stream.
  */
  p << std::cin;

  /*
    Invece, questa riga sarebbe la vera figata.
    Ma è sensato che non funzioni: chiamiamo il metodo ">>" definito sull'oggetto "std::cin",
    che non può prendere in input una Person.
  */
  // std::cin >> p;
  return 0;
}
