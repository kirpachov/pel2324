#include<iostream>

int main() {
  try {
    throw 3;
  } catch(int e){
    std::cout << "catturata eccezzione di tipo " << e << std::endl;
  }
	return 0;
}
