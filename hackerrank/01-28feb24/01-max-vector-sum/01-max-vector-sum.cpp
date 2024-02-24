#include<vector>
#include<iostream>
#include <bits/stdc++.h>

int trova_somma_massima(const std::vector<int> & v){
	// Mi serve un vettore che possa modificare
	std::vector<int> v_cp;
	for(const int &vi: v)
		v_cp.push_back(vi);

	std::sort(v_cp.begin(), v_cp.end());
	return v_cp.at(v_cp.size() - 1) + v_cp.at(v_cp.size() - 2);
}

void leggi(std::vector<int>& v) {
  int dim;
  std::cin>>dim;
  
  for (int i=0; i<dim; i++){
    int e;
    std::cin>>e; 
    v.push_back(e);
  } 
}

int main() {
  int s;
  std::vector<int> myv;

  leggi(myv);

  s = trova_somma_massima(myv);

  std::cout << s;

  return 0;
}

