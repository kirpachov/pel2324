#include<iostream>
#include<memory>

void something(){
  
}

using namespace std;

int main(){
  std::unique_ptr<int> p1 = std::make_unique<int>(20);
  std::cout << p1;
  
  return 0;
}
