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
    // TODO remove row 'r'
    // TODO remove 'c'
    
    return res;
}

int SquareMat::determinant() const {
    // TODO calc determinant
    return 15;
}

int SquareMat::size() const {
    return data.size();
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
  SquareMat y{x};
  y.at(0,0) = 25;
  x.print();
  y.print();

  return 0;
}
