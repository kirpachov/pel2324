#include<vector>
#include<iostream>
#include<cassert>

void print(const std::vector<int>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}

bool is_prime(const int num){
  assert(num > 1);

  //if (num % 2 == 0) return false;
  bool is_prime = true;
  for(int i = 2; i < (num / 2) + 1; i++){
    if (num % i == 0) is_prime = false;
  }

  return is_prime;
}

int next_prime(int num){
  bool found = false;
  do {
    num++;
    found = is_prime(num);
  } while (!found);

  return num;
}


std::vector<int> fill_with_primes(int size) {
  std::vector<int> a;
  int last_prime = 2;

  while(a.size() < size){
    a.push_back(last_prime);

    // May be doing one call more than needed.
    last_prime = next_prime(last_prime);
  }

  return a;
}

int main() {
  int size;

  std::cin>>size;

  std::vector<int> v;

  v = fill_with_primes(size);

  print(v);

  return 0;
}

