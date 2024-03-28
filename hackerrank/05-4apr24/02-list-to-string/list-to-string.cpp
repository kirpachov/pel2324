#include<iostream>
#include<string>

using std::string;

struct Cella{
  string info;
  Cella* next;
};

typedef Cella* Lista;

void prepend(Lista& l, const string& s) {
  Lista nuova = new Cella;

  nuova->next=l;
  nuova->info = s;
  l=nuova;
}


void append(Lista& l, const string& s) {
  if (!l)
    prepend(l, s);
  else
    append(l->next, s);
}

void leggi(Lista& l) {
  int e;
  std::cin>>e;

  while (e>0) {
    string buffer;
    std::cin>>buffer;
    append(l, buffer);
    e--;
  }
}

void distruggi(Lista& l) {
  if (l) {
    distruggi(l->next);
    delete l;
    l=nullptr;
  }
}


string concat(Lista l, int pos, int len) {
  // Try to find the first node to concat.
  while(pos > 0 && l != nullptr){
    l = l->next;
    pos--;
  }
  
  // If:
  // - could not find first node to concat (pos > list.size)
  // - list points to null pointer
  // - elements to print from this point are <= 0 (we're done adding strings)
  // return empty string.
  if (pos != 0 || l == nullptr || len <= 0) return std::string{""};

  // otherwise, returrn current node string concatenated with next node's string.
  return l->info + concat(l->next, 0, len - 1);
}
    
int main() {
  Lista l = nullptr;
  int da, quanti;

  leggi(l);

  std::cin>>da;
  std::cin>>quanti;

  std::cout<<concat(l, da, quanti);

  distruggi(l);

  return 0;
}



