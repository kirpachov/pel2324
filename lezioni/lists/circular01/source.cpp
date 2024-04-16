#include<iostream>

struct Cell {
  int info;
  Cell* next;
};

typedef Cell* pCell;

int count(pCell c){
  if (!c) return 0;

  int count = 1;
  pCell any = c->next;
  while(any && any != c){
    c = c->next;
    count ++;
  }

  return count;
}

void deleteCell(pCell c){
  if (!c) return;

  pCell paletto = c;
  do {
    pCell i = c->next;
    delete(i);
    c = i;
  } while(c && c != paletto);
}

// Scrivere una funzione che riconosca se una lista è circolare (1) oppure lineare(0)
int is_circ(pCell c){
  if (!c) return 0;
  if (c == c->next) return 1; // Lista circolare con 1 elemento
  
  const pCell paletto = c->next;
  while (c && paletto != c) c = c->next;

  // Se paletto è uguale a c, abbiamo fatto il giro completo.
  return paletto == c;
}

int main(){
  return 0;
}
