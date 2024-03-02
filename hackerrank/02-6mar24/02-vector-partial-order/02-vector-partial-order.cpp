#include <iostream>
#include <vector>
using namespace std;

vector<int> read_vector() {
    int size;
    vector<int> res;
    std::cin>>size;

    for( ; size>0; size--) {
      int elem;
      std::cin>>elem;
      res.push_back(elem);
    }
    return res;
}

void print_vector(const vector<int>& v) {
    for (int el: v) {
        std::cout<<el<<std::endl;
    }
}

void ordinamento_parziale(vector<int>& vect, const vector<int>& pos) {
  for(int i = 0; i < pos.size(); i++){
    int i_num = vect.at(pos.at(i));
    for(int j = 0; j < pos.size(); j++){
      const int j_num = vect.at(pos.at(j));
      if (j_num > i_num){
        vect.at(pos.at(j)) = i_num;
        vect.at(pos.at(i)) = j_num;
        i_num = j_num;
      }
    }
  }
}

int main() {
    vector<int> input = read_vector();
    vector<int> positions = read_vector();

    ordinamento_parziale(input, positions);

    print_vector(input);
    
    return 0;
}
