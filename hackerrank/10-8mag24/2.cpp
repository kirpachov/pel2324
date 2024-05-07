#include<iostream>
#include<string>

using namespace std;

class Dict {
  public:
    Dict();
    ~Dict();

    int& at(string pos);
    void print() const;
    bool operator<=(const Dict& d) const;
    bool operator==(const Dict& d) const;
    Dict& operator+=(const Dict& d);

  private:
    struct Cella {
      string key;
      int val;
      Cella* next;
    };

    typedef Cella* pCella;

    pCella head;
    int& push_back(const string& pos, const int val);
    int& push_back(const Dict::pCella& prev, const string& pos, const int val);
    bool has_key(const string& pos) const;
    bool has_pair(const string& pos, const int val) const;
    bool is_empty() const;
};

//Costruttore di default. Non cambiare
Dict::Dict() {
  head = nullptr;
}

//Distruttore: Non cambiare
Dict::~Dict() {
  pCella pc;
  while (head) {
    pc = head;
    head = head->next;
    delete pc;
  }
}

//Stampa gli elementi. Non cambare
void Dict:: print() const {
  cout<<"OUTPUT"<<endl;
  pCella pc = head;

  while (pc) {
    cout<<pc->key<<":"<<pc->val<<endl;
    pc = pc->next;
  }
  cout<<"---"<<endl;
}

/*
    Add a element at the end of the list.
*/
int& Dict::push_back(const string& pos, const int val){
    if (is_empty()) {
        head = new Cella();
        head->key = pos;
        head->val = 0;
        return head->val;
    }
    
    Dict::pCella h = head;
    while(h->next && h->key != pos){
        h = h->next;
    }
    
    // assert(h->next == nullptr);
    return push_back(h, pos, val);
}

/*
    Add a certain next to @param prev
*/
int& Dict::push_back(const Dict::pCella& prev, const string& pos, const int val){
    prev->next = new Cella();
    prev->next->key = pos;
    prev->next->val = 0;
    return prev->next->val;
}

bool Dict::has_key(const string& pos) const {
    if (is_empty()) return false;

    Dict::pCella h = head;
    while(h && h->key != pos) h = h->next;
    
    return h != nullptr;
}

bool Dict::has_pair(const string& pos, const int val) const {
    if (is_empty()) return false;

    Dict::pCella h = head;
    while(h && h->key != pos) h = h->next;
    
    return h != nullptr && h->val == val;
}

bool Dict::is_empty() const {
    return head == nullptr;
}

//Esercizio 1
//Implementare: il metodo at ritorna una reference al
//campo value del nodo con la key uguale a pos se questa esiste
//altrimenti crea un nuovo nodo in coda alla lista che contiene
//come key pos e come valore 0, e ritorna la reference al campo
//value di questo nuovo nodo
int& Dict::at(string pos) {
    if (!has_key(pos)) return push_back(pos, 0);

    Dict::pCella h = head;
    while(h->next && h->key != pos) h = h->next;

    return h->val;
}



//Esercizio 2
//Ritorna true se *this ha un sottoinsieme degli elementi
//di d, cioe' tutte le coppie key,value di *this sono anche
//in Dict (anche in ordine diverso) 
bool Dict::operator<=(const Dict& d) const {
    if (d.is_empty()) return is_empty();

    pCella h = head;
    bool less_or_eq = true;
    while(h && less_or_eq) {
        less_or_eq &= d.has_pair(h->key, h->val);

        h = h->next;
    }

  return less_or_eq;
}

//Esercizio 2
//Ritorna true se *this ha gli stessi elementi
//di d anche in ordine diverso
bool Dict::operator==(const Dict& d) const {
    return *this <= d && d <= *this;
}

//Esercizio 3
//Aggiunge tutti gli elementi del parametro formale la cui chiave
//non e' gia' presente in *this. 
//In altre parole, per ogni elemento di d, se la sua key e' gia'
//presente in *this, allora viene ignorato, se invece non e'
//presente, va aggiunto in coda. Al termine si ritorna *this

Dict& Dict::operator+=(const Dict& d) {
  
  return *this;
}


void leggi(Dict& s) {
  int nelem;
  string k;
  int v;
  cin>>nelem;
  for (int i=0; i<nelem; i++) {
    cin>>k;
    cin>>v;
    s.at(k)=v;
  }
}

int main() {
  Dict d1, d2;
  leggi(d1);
  leggi(d2);
  
  if (d1 <= d2)
    cout<<"d1<=d2"<<endl;
  
  if (d2 == d1)
    cout <<"d1==d2"<<endl;
  else
    cout <<"d1!=d2"<<endl;

  return 0;
}
