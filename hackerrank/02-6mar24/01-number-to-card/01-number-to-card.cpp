#include<iostream>
#include<vector>

using std::vector;
using std::string;

string carta(int n) {
  if (n < 0 || n > 39) return "Errore di conversione";

  const std::vector<std::string> card_names = {
    "Asso",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "Donna",
    "Cavallo",
    "Re"
  };

  std::vector<std::string> suites = {
    "denari",
    "coppe",
    "bastoni",
    "spade"
  };

  std::string card_name = card_names.at(n % 10);

  switch(n){
    case 1: {
      card_name = "Asso";
      break;
    }
    case 8: {
      card_name = "Donna";
      break;
    }
    case 9: {
      card_name = "Fante";
      break;
    }
    case 10: {
      card_name = "Re";
      break;
    }
  }
  
  return card_name + " di " + suites.at(n / 10) ;
}

int main() {
  int c; 
  string cstr;
  std::cin>>c;
  std::cout<<"**";
  cstr = carta(c);
  std::cout<<"**";
  std::cout<<std::endl<<cstr<<std::endl;
  return 0;
}
