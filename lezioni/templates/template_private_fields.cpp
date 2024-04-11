#include<iostream>

/**
  La domanda è:
  Se ho una classe generica my_val<T>,
  e ho due istanze di questa classe:
  "a" è di tipo my_val<int> 
  "b" è di tipi my_val<double>

  "a" può accedere ai campi privati di b?
  Entrambe sono istanze di my_val, ma hanno una piccola differenza.

  RISPOSTA: no. "a" non può accedere ai campi privati di "b". La prova è visibile decommentando la riga 40 e provando a compilare.
*/

template <typename T>
struct my_val {
  my_val(T value){
    priv_val = value;
  }

  T get_priv_val() {
    return priv_val;
  }

  template <typename G>
  void read_my_private_field(my_val<G> v) const {
    // attenzione. Se T != G, la prossima riga darà errore in fase di compilazione.
    std::cout << "v.priv_val: " << v.priv_val << std::endl;

    // Questa riga non fallisce mai: si chiama il metodo pubblico ed è perfettamente lecito.
    std::cout << "v.get_priv_val(): " << v.get_priv_val() << std::endl;
  }

  private:
  T priv_val;
};

int main(){
  my_val<int> a(3);
  my_val<int> a1{5};

  my_val<double> b(3.3);

  // error: ‘double my_val<double>::priv_val’ is private within this context
  // a.read_my_private_field(b);

  // This line is ok.
  a.read_my_private_field(a1);

  return 0;
}
