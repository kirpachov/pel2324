#include<iostream>
#include<vector>

void posiziona_regina(std::vector<std::vector<char>>& m, const int row, const int col){
	std::cout << "ciao" << std::endl;
}

void rimuovi_regina(std::vector<std::vector<char>>& m, const int row, const int col){
	std::cout << "ciao" << std::endl;
}

bool regine(std::vector<std::vector<char>>& m, int c){
	if (c < 8){
		bool found = false;
		int r = 0;
		while(!found && r < 8) {
			if (m.at(r).at(c) == 0) {
				posiziona_regina(m, r, c);

				// Trovato la configurazione valida
				if (regine(m, c + 1)) {
					found = true;
				} else {
					rimuovi_regina(m, r, c + 1);
				}
			}

			r++;
		} // end while (r < 8)

		return found;
	} else {
		return true;
	}
}

int main(void){
	return 0;
}