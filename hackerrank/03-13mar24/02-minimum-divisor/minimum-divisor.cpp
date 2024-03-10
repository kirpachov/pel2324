#include<vector>
#include<iostream>

void print(const std::vector<double>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}


void read(std::vector<double>& v) {
  int size;
  double el;
  std::cin>>size;

  v.clear(); //cancella tutti gli elementi del vettore
  for (;size>0;size--) {
    std::cin>>el;
    v.push_back(el);
  }
}


std::vector<double> moving_average(const std::vector<double> v, int k) {
    std::vector<double> result(v.size());

    for(auto a: v) std::cout << a<< std::endl;

    return result;
}
int main() {
  std::vector<double> v;

  int mov;
  
  std::cin>>mov;

  read(v);

  std::vector<double> result;

  result = moving_average(v, mov);

  print(result);

  return 0;
}