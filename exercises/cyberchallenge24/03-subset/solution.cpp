#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

vector<int> getright(vector<int> set, int treshold) {
  vector<int> res(set.size());
  int j = set.size() - 1;
  for (int i = set.size() - 1; i >= 0; i--) {
    while (j >= 0 && set[j] - set[i] > treshold)
      j--;
    res[i] = j;
  }
  return res;
}

vector<int> getleft(vector<int> set, int treshold) {
  vector<int> res(set.size());
  int j = 0;
  for (int i = 0; i < set.size(); i++) {
    while (j < set.size() && set[i] - set[j] > treshold)
      j++;

    res[i] = j;
  }
  return res;
}

void print_vector(const vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i);
    if (i + 1 < v.size()) cout << " ";
  }
}

void print_vector(const vector<int> &v, const string label) {
  cout << label << ": (";
  print_vector(v);
  cout << ") " << endl;
}

int find_subsets(int treshold, vector<int> set) {
  sort(set.begin(), set.end());
  vector<int> right_set = getright(set, treshold);
  vector<int> left_set = getleft(set, treshold);

  vector<int> ls(set.size());
  for (int i = 0; i < set.size(); i++) {
    ls[i] = i - left_set[i] + 1;

    /**
     * Inizialmente avevo difficoltà a capire il perché di questa riga.
     * Il perché è in realtà sensato:
     * In grandi dataset il set di sinistra sarà molto lontano dal set di destra.
     * In questo caso, per trovare qual'è la combinazione ideale tra set di sinistra e set di destra,
     * dovremmo scorrere molte volte le soluzioni presenti in `ls` e `rs`.
     *
     * Ma noi cerchiamo quel punto da cui possiamo dividere serenamente il set iniziale e sapere che a sinistra/prima
     * di quel punto abbiamo il set di sinistra, e a destra/dopo di quel punto abbiamo il set di destra.
     * Non ci interessa sapere dov'è il set o com'è composto quindi.
     *
     * Ecco qui: se in passato abbiamo trovato soluzioni migliori di quelle che abbiamo trovao in questa iterazione,
     * buttiamo via questa iterazione e portiamo aventi la soluzione migliore.
     *
     * In questo modo l'ultimo ciclo in questa funzione potrà scorrere l'array solo una volta e trovare quel
     * punto "divisore".
     *
     * La stessa logica si applica (vice versa, dalla fine all'inizio) nel prossimo ciclo, per la stessa ragione.
     */
    if (i > 0) ls[i] = max(ls[i], ls[i - 1]);
  }

  vector<int> rs(set.size());
  for (int i = set.size() - 1; i >= 0; i--) {
    rs[i] = right_set[i] - i + 1;

    if (i < set.size() - 1) rs[i] = max(rs[i], rs[i + 1]);
  }

  int ans = 0;
  for (int i = 0; i < set.size() - 1; i++)
    /**
     * Perché prendiamo l'elemento `i` di `ls` ma i + 1 di rs??
     *
     * Perché altrimenti avremmo sovrapposizione. Invece in questo modo confrontiamo sempre due set distinti.
     */
    ans = max(ans, ls[i] + rs[i + 1]);

  return ans;
}

int main() {
  int cases_count;
  cin >> cases_count;

  while (cases_count--) {
    int numbers_current_case, treshold;
    vector<int> set;
    cin >> numbers_current_case >> treshold;

    for (int i = 0; i < numbers_current_case; i++) {
      int x;
      cin >> x;
      set.push_back(x);
    }

    cout << find_subsets(treshold, set) << endl;
  }

  return 0;
}