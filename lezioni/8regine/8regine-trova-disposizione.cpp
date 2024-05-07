#include<iostream>
#include<vector>

using std::vector;

class Scacchiera{
	public:
		Scacchiera();

		void metti_regina(int r, int c);
		void togli_regina(int r, int c);
		bool libera(int r, int c) const;

		void stampa() const;
	private:
		vector<vector<int>> s;
};


Scacchiera::Scacchiera() {
	s.resize(8, vector<int>(8, 0));
}

void Scacchiera::metti_regina(int r, int c) {
	if (r<8 && c<8 && r>=0 && c>=0 && s.at(r).at(c)==0) {
		for (int j=0; j<8; j++) {
			s.at(j).at(c)++;   //colonna
			s.at(r).at(j)++;   //riga

			if (c-r+j>=0 && c-r+j<8)   //diagonale principale
				s.at(j).at(c-r+j)++;

			if (c+r-j>=0 &&c+r-j<8)   //diagonale secondaria
				s.at(j).at(c+r-j)++;
		}
		s.at(r).at(c) = -1;
	}

}

void Scacchiera::togli_regina(int r, int c) {
	if (r<8 && c<8 && r>=0 && c>=0 && s.at(r).at(c)==-1) {
		for (int j=0; j<8; j++) {
			s.at(j).at(c)--;   //colonna
			s.at(r).at(j)--;   //riga

			if (c-r+j>=0 && c-r+j<8)   //diagonale principale
				s.at(j).at(c-r+j)--;

			if (c+r-j>=0 &&c+r-j<8)   //diagonale secondaria
				s.at(j).at(c+r-j)--;
		}
		s.at(r).at(c) = 0;
	}
}

bool Scacchiera::libera(int r, int c) const {
	return (s.at(r).at(c) == 0);
}

void Scacchiera::stampa() const {
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (s.at(i).at(j)==-1)
				std::cout<<'Q';
			else
				std::cout<<".";
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
}

bool regine(int q, Scacchiera& s) {
	if (q==0)
		return true;
	else
	{
		int wc = 8-q;
		bool found = false;

		for (int r = 0; r<8; r++) {
			if (!found && s.libera(r,wc)) {
				s.metti_regina(r,wc);
				found = regine(q-1, s);
				if (!found) 
					s.togli_regina(r, wc);
			}
		}

		return found;
	}
}



int main() {
	Scacchiera s,s1;
	s.stampa();
	if (regine(8, s)) {
		std::cout<<"Soluzine trovata!"<<std::endl;
		s.stampa();
	}
	else {
		std::cout<<"Soluzione non trovata"<<std::endl;
	}

	return 0;
}
