#include<iostream>

class Str {
  public:
    int num;
    Str(int new_num){
      std::cout << "creato " << new_num << std::endl;
      num = new_num;
      numx2 = new_num * 2;
    }

    ~Str(void){
      std::cout << "eliminato " << num << std::endl;
    }

    Str(const Str& copy){
      // Attenzione!!!
      // Qui posso accedere al campo privato "numx2" ma solo perché il parametro è dello stesso tipo
      num = copy.num;
      numx2 = copy.numx2;
      std::cout << "costruttore dello stesso tipo del parametro" << std::endl;
    }

  private:
    int numx2;
};

int main(void){
  Str a{1};
  {
    std::cout << "Blocco" << std::endl;
    Str b{2};
  }

  std::cout << "fuori blocco" << std::endl;

  Str c{a};

  /*
    Nota: farà il logging della creazione e dell'uccisione di #1 due volte perché c copia da a.
  */
  return 0;
}
