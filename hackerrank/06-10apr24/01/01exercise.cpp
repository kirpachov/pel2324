#include<iostream>

class List_uguali{
  public:
    List_uguali();
    List_uguali(const List_uguali& l);

    void aggiungi(int elem);
    void rimuovi(int elem);
    void stampa() const;

    List_uguali operator+(const List_uguali& l) const;
    List_uguali& operator=(const List_uguali& l);

    ~List_uguali();

  private:
    struct Cella;
    typedef Cella* pCella;

    pCella list;
};

struct List_uguali::Cella {
  //Definisci qui le informazioni da mettere nella cella
  pCella m_next;
  int m_info;
  Cella();
  Cella(const int);
  Cella(const int, const pCella&);

  // List_uguali::pCella find(const int);

  private:
  void reset(void);
};

List_uguali::Cella::Cella(){
  reset();
}

List_uguali::Cella::Cella(const int info) {
  reset();
  m_info = info;
}


List_uguali::Cella::Cella(const int info, const pCella& next){
  reset();
  m_info = info;
  m_next = next;
}

void List_uguali::Cella::reset(void) {
  m_info = 0;
  m_next = nullptr;
}

// Costruttore di default: non modificare il metodo
List_uguali::List_uguali() {
  list = nullptr;
}

// Distruttore: non modificare il metodo
List_uguali::~List_uguali() {
  pCella p = list;
  while(p) {
    p = p->m_next;
    delete list;
    list=p;
  }
}

// Implementare: Esercizio 1
// Aggiungi un elemento alla lista
void List_uguali::aggiungi(const int info) {
  if (list == nullptr){
    list = new Cella{info};
    return;
  }

  pCella l = list;
  while(l != nullptr && l->m_info != info && l->m_next != nullptr)
    l = l->m_next;

  l->m_next = new List_uguali::Cella(info, l->m_next);
}

// Implementare: Esercizio 1
// Stampa gli elementi della lista
void List_uguali::stampa() const {
  pCella l = list;
  while(l != nullptr) {
    std::cout << l->m_info << std::endl;
    l = l->m_next;
  }
}

// Implementare: Esercizio 1
// Rimuovi un elemento dalla lista
void List_uguali::rimuovi(const int info) {
  if (list == nullptr) return;
  if (list->m_info == info){
    pCella l = list;
    list = list->m_next;
    delete l;
    return;
  }

  pCella l = list;

  // Qui si poteva fare tutto in un unico while
  // ma avremmo avuto molti accessi 'inutili' alla memoria.
  // si avrebbe avuto quindi avuto codice più pulito ma meno efficiente.
  if (l != nullptr && l->m_info != info)
    while(l->m_next != nullptr && l->m_next->m_info != info) l = l->m_next;

  // Elemento non presente nella lista.
  if (l == nullptr) return;

  // TODO delete element from memory
  pCella to_delete = l->m_next;
  l->m_next = to_delete == nullptr ? nullptr : to_delete->m_next;
  delete to_delete;
}

//Implementare: Esercizio 2
//Ridefinizione del copy constructor
List_uguali::List_uguali(const List_uguali& l) {
  pCella p = l.list;

  while(p != nullptr) {
    // Qui al posto di aggiungi si potrebbe definire un metodo push_back,
    // ma in questo specifico caso aggiungi andrà bene.
    aggiungi(p->m_info);
    p = p->m_next;
  }
}

//Implementare: Esercizio 3
List_uguali& List_uguali::List_uguali::operator=(const List_uguali& l) {
  return *this;
}


//Implementare: Esercizio 3
List_uguali List_uguali::List_uguali::operator+(const List_uguali& l) const{
  List_uguali res;
  return res;

}

void leggi_lista(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.aggiungi(e);
  }
}

void rimuovi(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.rimuovi(e);
  }
}

void leggi_ancora(List_uguali l) {
  leggi_lista(l);
  std::cout<<"Output copia"<<std::endl;
  l.stampa();
}

int main() {
  List_uguali l;
  leggi_lista(l);
  rimuovi(l);
  leggi_lista(l);
  std::cout<<"Output"<<std::endl;
  l.stampa();

  return 0;
}

