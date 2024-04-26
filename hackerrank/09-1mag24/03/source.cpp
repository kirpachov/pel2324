#include<iostream>
#include<vector>
#include<list>



class SquareMat{
  /*non modificare la parte pubblica*/
  public:
    SquareMat(int dim);
     SquareMat(const SquareMat& s);
    ~SquareMat();
    void read();
    int& at(int r, int c);
    const int& at(int r, int c) const;
    void print() const;
    SquareMat reduce(int r, int c) const;
     int determinant() const;
     int size() const;

  private:
    /*Metodi privati e stato della classe */
    std::vector<std::vector<int>> data;
};

SquareMat::SquareMat(int dim){
    data = std::vector<std::vector<int>>();
    for(int i = 0; i < dim; i++){
        std::vector<int> v = std::vector<int>();
        for(int j = 0; j < dim; j++) v.push_back(0);

        data.push_back(v);
    }
}

SquareMat::SquareMat(const SquareMat& s): SquareMat(s.size()) {
    for(int row = 0; row < s.size(); row++){
        for(int col = 0; col < s.size(); col++){
            at(row, col) = s.at(row, col);
        }
    }
}

SquareMat::~SquareMat(){
    // vector destructor will be called. Nothing to do.
}

int& SquareMat::at(int r, int c){
    if (r > size() || c > size()) { /* may throw error... */ }
    
    return data.at(r).at(c);
}

const int& SquareMat::at(int r, int c) const {
    if (r > size() || c > size()) { /* may throw error... */ }
    
    return data.at(r).at(c);
}

SquareMat SquareMat::reduce(int r, int c) const {
    SquareMat res = SquareMat{*this};
    
    for(int i = 0; i < res.size(); i++){
        for(int j = c; j < res.size() - 1; j++){
            res.data.at(i).at(j) = res.data.at(i).at(j + 1);
        }

        res.data.at(i).pop_back();
    }
    
    for(int i = r; i < res.size() - 1; i++){
        res.data.at(i) = res.data.at(i + 1);
    }
    res.data.pop_back(); // remove last duplicated
    
    
    return res;
}

int pow(const int num, const int power){
    int acc = 1;
    for(int i = 0; i < power; i++) acc = acc * num;

    return acc;
}

int SquareMat::determinant() const {
    if (size() == 1) return data.at(0).at(0);

    int acc = 0;
    
    for(int i = 0; i < size(); i++){
        acc += pow(-1, i) * at(0, i) * reduce(0, i).determinant();
    }
    
    return acc;
}

int SquareMat::size() const {
    return data.size();
}

bool is_prime(const int num){
    if (num <= 1) return false;

  bool is_prime = true;
    int i = 2;
    while(is_prime && i < (num / 2) + 1){
        if (num % i == 0) is_prime = false;

        i++;
    }
  return is_prime;
}

bool allprimes(const SquareMat& mat){
    int row = 0;
    bool all_primes = true;
    while(all_primes && row < mat.size()){
        int col = 0;
        while(all_primes && col < mat.size()){
            if (!is_prime(mat.at(row, col))) all_primes = false;
            col++;
        }
        row++;
    }

    return all_primes;
}

/*Non modificare il seguente metodo*/
void SquareMat::read() {
  for (int i=0; i<this->size(); i++)
    for (int j=0; j<this->size(); j++) 
      std::cin>>this->at(i,j);
}

/*non modificare il seguente metodo*/
void SquareMat::print() const{
  for (int i=0; i<this->size(); i++) {
    for (int j=0; j<this->size(); j++) 
      std::cout<<this->at(i,j)<<" ";
    std::cout<<std::endl;
  }
}
int main() {
  int dim;
  std::cin>>dim;
  
  SquareMat x(dim);
  x.read();

  if (allprimes(x))
	  std::cout<<"Tutti primi"<<std::endl;
  else
	  std::cout<<"Almeno un numero non primo"<<std::endl;

  return 0;
}