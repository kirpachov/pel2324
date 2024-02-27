#include <iostream>
#include <vector>

// Esercizio 19 feb 24
// Leggere una sequenza di int che termina quando vengono inseriti 2 numeri uguali consecutivi
void es19feb24_1(void){
	int lastone;
	std::cin >> lastone;
	bool found = false;
	do {
		int current;
		std::cin >> current;
		if (current == lastone) found = true;
		else lastone = current;
	} while(!found);

	std::cout << "Trovato due volte il numero " << lastone << std::endl;
}


// Leggi 10 interi e stampa "Si" se almeno un elemento della sequenza è pari.
// PATTER ESISTENZIALE
void pattern_esistenziale(void){
	bool found = false;
	for(int i = 0; i < 10; i++){
		int k;
		std::cin >> k;
		if (k % 2 == 0) found = true;
	}

	if (found) std::cout << "Si" << std::endl;
}

// Leggi 10 numeri da tastiera e stampa si se sono tutti maggiori di 100
void pattern_universale(void){
	bool risp = true;
	for(int i = 0; i < 10; i++){
		int k;
		std::cin >> k;
		if (k <= 100) risp = false;
	}

	if (risp) std::cout << "si" << std::endl;
}

/**
  * Verify if all columns of a matrix have the same sum
  * Note: method not tested.
  */
bool test26feb24(const std::vector<std::vector<int>> &matrix){
  std::vector<int> sums(matrix.size());

  for(int i = 0; i < matrix.size(); i++)
    for(int j = 0; j < matrix.at(0).size(); j++)
      sums.at(j) += matrix.at(i).at(j);

  bool equals = true;

  for(int i = 1; i < sums.size(); i++)
    if (sums.at(i) != sums.at(0))
      equals = false;

  return equals;
}

int main() {

	// es19feb24_1();
	// pattern_esistenziale();
	//pattern_universale();
  return 0;
}
