#include <string>
#include <iostream>

void rimuovidoppie(std::string &s) {
  if (s.length() <= 1) return;

  int w = 1;
  for(int i = 1; i < s.length(); i++){
    if (s.at(i) != s.at(i - 1)){
      s.at(w) = s.at(i);
      w++;
    }
  }

  s = s.substr(0, w);
}

int main() {
    std::string a;
    getline(std::cin, a);
    
    rimuovidoppie(a);
    
    std::cout << a << std::endl;
    
    return 0;
}
