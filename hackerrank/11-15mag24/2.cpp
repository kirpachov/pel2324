#include<iostream>
#include<vector>
#include<list>

class Polynomial{
  public:
    Polynomial();
    Polynomial(const Polynomial& p);
    void set(int exponent, int coeff);
    int at(int exponent) const;
    void read();
    int evaluate(int x) const;
    Polynomial differentiate(int order) const;
    int degree() const;
    void print() const;
    
  private:
    int intpow(int base, int exponent) const;
    
    /**
    first is exponent, second is coefficient
    */
    std::vector<std::pair<int, int>> m_members;
};


//////// Pre-implemented part/////////////

//Do not change this method! It reads a Polynomial 
void Polynomial::read() {
  int coeff, exponent;
  do {
    std::cin >> exponent;
    if (exponent >=0 )  {
      std::cin >> coeff;
      set(exponent, coeff);
    }
  } while (exponent>=0);
}


//Do not change this method! It prints a Polynomial
void Polynomial::print() const {
  int n = degree();

  for (int i=0; i<=n; i++) {
    if (at(i)!=0) 
      std::cout<<"+("<<at(i)<<")x^"<<i;
  }
  std::cout<<std::endl;
}



//Do not change this method! It simply computes the integer power
//It could be useful!
int Polynomial::intpow(int base, int exponent) const {
  int res=1;

  while (exponent>0) {
    res = res*base;
    exponent--;
  }
  return res;
}


// Methods for exercise 1


// Default constructor: builds the polynomial 0
Polynomial::Polynomial() {
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& p) {
    m_members = p.m_members;
}

//Returns the coefficient of the terms  x^exponent
//If it has not been added it returns 0
//Notice that we have only one version of at
//It does not return a reference, just an int. So we can only read with at!
int Polynomial::at(int exponent) const {
  for(auto i: m_members)
    if (i.first == exponent)
      return i.second;
  
  return 0;
}



//Set to coeff the coefficient of x^exponent. If this is present, 
//it will be overwritten. Setting the coefficient to 0 means 
//the removal from the polynomial representation
void Polynomial::set(int exponent, int coeff) {
  bool found = false;
  int index = 0;
  while(index < m_members.size() && !found){
    auto i = m_members.at(index);

    if (i.first == exponent) {
      m_members.at(index).second = coeff;
      found = true;
    }
    
    index++;
  }

  if (!found) m_members.push_back(std::pair<int, int>{exponent, coeff});
}

//Evaluate a polynomial for a certain x
int Polynomial::evaluate(int x) const {
  int acc = 0;
  
  for(auto member: m_members) {
    acc += intpow(x, member.first) * member.second;
  }
  
  return acc;
}


//Methods for exercise 2


//Returns the degree of a polynomial. The polynomial 0 has degree 0
int Polynomial::degree() const {
  // if (m_members.empty()) return 0;
  
  int max = 0;
  for(auto m: m_members)
    if(m.first > max && m.second != 0)
      max = m.first;
  
  return max;
}



//Methods for exercise 3

//This *recursive* function computes the n-th derivative of the polynomial
Polynomial Polynomial::differentiate(int order) const {
  if (order <= 0) return *this;
  
  Polynomial p;
  for(auto member: m_members) {
    int exponent = member.first;
    int coeff = member.second;
    p.set(exponent - 1, exponent * coeff);
  }
  
  return p.differentiate(order - 1);
}

int main() {
  Polynomial x;
  x.read();
  
  x.print();

  return 0;
}