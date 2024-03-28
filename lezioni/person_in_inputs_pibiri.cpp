#include <iostream>

struct Person {
    std::string fullname;
    int age;
    float weight;

    // void operator<<(std::istream &is) {
    //   std::cout << "Inser user fullname and press enter. Can be blank."
    //             << std::endl;
    //   std::getline(is, m_fullname);
    //   std::cout << "User's name: '" << m_fullname << "'" << std::endl;
    // }
};

std::istream& operator>>(std::istream& is, Person& p) {
    std::getline(is, p.fullname, ' ');
    is >> p.age;
    is >> p.weight;
    return is;
}

std::ostream& operator<<(std::ostream& os, Person const& p) {
    os << "(name:" << p.fullname << "|age:" << p.age << "|weight:" << p.weight
       << ")";
    return os;
}

int main(void) {
    Person p;

    /*
      La prima riga funziona e ha senso che funzioni:
      chiamiamo il metodo "<<" sull'oggetto di tipo "Person",
      che prende in input uno stream.

      Giulio: ma questo invoca l'operatore << non >> che
      e' quello che vuoi. Quindi, questo e' un errore logico.
      La sintassi corretta è quella nel commento successivo.
    */
    // p << std::cin;

    /*
      Invece, questa riga sarebbe la vera figata.
      Ma è sensato che non funzioni: chiamiamo il metodo ">>" definito
      sull'oggetto "std::cin", che non può prendere in input una Person.

      Giulio:
      Guarda l'overloading (sovraccarico alla riga 16).
      Stai arricchendo la semantica di operator>> a lavorare
      anche con il tipo Person.
      Nota che NON stai chiamando il metodo >> di std::cin.
      operator>> e' una funzione che accetta due argomenti:
      il primo è un generico stream di input (es. std::cin),
      mentre il secondo e' una variabile del tipo che vuoi
      estrarre.
    */
    std::cin >> p;

    // Giulio: queste tre stampe possono essere
    // rimpiazzate da un elegante std::cout << p << std::endl;
    // ma per farlo, mi serve un altro overloading
    // (vedi quello della riga 23.)
    std::cout << p.fullname << std::endl;
    std::cout << p.age << std::endl;
    std::cout << p.weight << std::endl;

    std::cout << p << std::endl;

    return 0;
}
