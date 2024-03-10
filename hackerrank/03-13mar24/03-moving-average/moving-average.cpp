#include<vector>
#include<iostream>
#include<cassert>

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

double average(std::vector<double> const&v, const int orig_from, int to){
  assert(orig_from <= to);
  assert(to >= 0);

  // In case invalid indexes are provided
  int from = orig_from >= 0 ? orig_from : 0;
  if (to > v.size() - 1) to = v.size() - 1;
 
  double div = to - from + 1, acc = 0;

  while(from <= to){
    acc += v.at(from);
    from++;
  }

  return acc / div;
}

std::vector<double> moving_average(const std::vector<double> v, int k) {
    std::vector<double> result(v.size());

    for(int i = 0; i < v.size(); i++){
      result.at(i) = average(v, i - k, i + k);
    }

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
