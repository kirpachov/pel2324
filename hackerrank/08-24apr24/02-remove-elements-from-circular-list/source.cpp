#include<iostream>
#include<cassert>

struct Cella_circ{
  int info;
  struct Cella_circ* next;
};


typedef Cella_circ* Lista_circ;


void add(Lista_circ& lista, int x) {
  Lista_circ nuovo = new Cella_circ;
  nuovo->info = x;
  if (lista==nullptr) {
    nuovo->next = nuovo;
    lista = nuovo;
  }
  else {
    nuovo->next = lista->next;
    lista->next = nuovo;
  }
}

//stampa lista
void stampa_lista(Lista_circ l) {
  if (l) {
    Lista_circ pc{l};
    do {
      std::cout<<l->info << " ";
      l=l->next;
    } while (l!=pc);
  }
  std::cout<<std::endl;
}

//distruggi lista
void distruggi(Lista_circ& l) {
  if (l) {  
    Lista_circ supp, sentinella{l};
    do {
      supp = l;
      l=l->next;
      delete supp;
    } while (l!=sentinella);
    l = nullptr;
  }
}

//leggi lista
void leggi_lista(Lista_circ& l) {
  int elem, n;
  std::cin>>n;
  while (n>0) {
    std::cin>>elem;
    add(l, elem);
    n--;
  }
}

void rimuovi_occ(Lista_circ& l, int elem){
  if (!l) return; // Empty list

  if (!l->next) return; // linear list

  // 1-element list
  if (l == l->next){
    if (l->info == elem) l = nullptr;

    return;
  }

  // Removing first element from list
  if (l->info == elem){
    Lista_circ last = l;
    while(last->next != l) last = last->next;

    assert(last->next == l);

    l = l->next;
    last->next = l;

    return rimuovi_occ(l, elem);
  }

  // Common case
  Lista_circ runner = l;
  while(runner->next != l){
    if (runner->info == elem) return rimuovi_occ(runner, elem);

    runner = runner->next;
  }
}

int main() {

  int elimina;
  Lista_circ l=nullptr;

  leggi_lista(l);
  std::cin>>elimina;

  std::cout<<"Prima: ";
  stampa_lista(l);

  rimuovi_occ(l, elimina);

  std::cout<<"Dopo: ";
  stampa_lista(l);


  distruggi(l);
  return 0;
}
