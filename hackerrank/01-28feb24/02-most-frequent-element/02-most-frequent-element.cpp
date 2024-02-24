#include<vector>
#include<iostream>
#include<unordered_map>
#include <bits/stdc++.h>

int trova_max_freq(const std::vector<int>& v) {
  if (v.size() == 0) return 0;

	std::unordered_map<int, int> hash;
  for(const int &num: v){
    if (hash.count(num) == 0) hash.insert({num, 0});

    hash.at(num) += 1;
  }


  int highest_frequency = 1;
  for(auto &x: hash){
    //std::cout << x.first << "\t" << x.second << std::endl;
    if (x.second > highest_frequency) highest_frequency = x.second;
  }

  std::vector<int> most_frequent;
  for(auto &x: hash){
    if (x.second == highest_frequency) most_frequent.push_back(x.first);
  }

  std::sort(most_frequent.begin(), most_frequent.end());

	return most_frequent.at(0);
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

  s = trova_max_freq(myv);

  std::cout << s <<std::endl;

  return 0;

}
