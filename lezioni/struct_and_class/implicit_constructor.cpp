#include<iostream>

struct obj {
  // ATTENZIONE. Se si definisce un costruttore, si perdono i costruttori di default.
  // obj(int num, char letter): m_num(num), m_letter(letter){}

  int m_num;
  char m_letter;

  friend std::ostream& operator<<(std::ostream& os, obj& obj){
    os << "num: " << obj.m_num << " letter: " << obj.m_letter;
    return os;
  }

  // ATTENZIONE.
  // Anche definendo campi privati si perdono i costruttori di default.
  private:
    // int a;
};

int main(){
  
  // Basic usage.
  // obj a;
  // a.m_letter = 'B';
  // a.m_num = 15;
  

  // Both fields: VALID.
  obj a{15, 'B'};

  // Only first field: VALID.
  // obj a{15};

  // obj a;

  std::cout << a << std::endl;
  
  return 0;
}
