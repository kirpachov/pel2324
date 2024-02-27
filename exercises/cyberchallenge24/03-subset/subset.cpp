#include <iostream>
#include <vector>
#include <bits/stdc++.h>

void print_vector(const std::vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    std::cout << "\t" << v.at(i);
    if (i + 1 < v.size()) std::cout << ", ";
  }
}

void print_vector(const std::vector<int> &v, const std::string label) {
  std::cout << label << ": \t";
  print_vector(v);
  std::cout << std::endl;
}

std::vector<int> get_left_anchors(const std::vector<int> &arr, const int treshold) {
  std::vector<int> left_anchors(arr.size());

  int a = 0;
  for (int i = 0; i < arr.size(); i++) {
    while (a < arr.size() && arr[i] - arr[a] > treshold) {
      a++;
    }

    left_anchors.at(i) = a;
  }

  return left_anchors;
}

std::vector<int> get_right_anchors(const std::vector<int> &arr, const int treshold){
  std::vector<int> right_anchors(arr.size());

  int j = arr.size() - 1;
  for(int i = arr.size() - 1; i > 0; i--){
    while(j > 0 && arr.at(j) - arr.at(i) > treshold)
      j--;

    right_anchors.at(i) = j;
  }

  return right_anchors;
}

int solve_case(std::vector<int> &arr, const int treshold) {
  std::sort(arr.begin(), arr.end());

//  print_vector(arr, "arr         ");

  std::vector<int> left_anchors = get_left_anchors(arr, treshold);
//  print_vector(left_anchors, "left_anchors");

  std::vector<int> right_anchors = get_right_anchors(arr, treshold);

  std::vector<int> ls(arr.size());
  for(int i = 0; i < arr.size(); i++){
    ls.at(i) = i - left_anchors.at(i) + 1;

    if (i > 0) ls.at(i) = std::max(ls.at(i), ls.at(i - 1));
  }

//  print_vector(ls, "ls    ");

//  print_vector(right_anchors, "right_anchors");

  std::vector<int> rs(arr.size());
  for(int i = arr.size() - 1; i > 0; i--){
    rs.at(i) = right_anchors.at(i) - i + 1;

    if (i < arr.size() - 1) rs.at(i) = std::max(rs.at(i), rs.at(i + 1));
  }

//  print_vector(rs, "rs     ");

  int best = 2;
  for(int i = 0; i < arr.size() - 1; i++){
//    std::cout << "i: " << i;
    const int left = ls.at(i);
//    std::cout << " left: " << left;
    const int right = rs.at(i + 1);
//    std::cout << " right: " << right;

//    std::cout << " best: " << best;

//    std::cout << std::endl;

    best = std::max(best, left + right);
  }

  return best;
}

int main(void) {
  size_t scenarios;
  std::cin >> scenarios;
  for (int i = 0; i < scenarios; i++) {
    std::vector<int> arr;
    int arr_size;
    std::cin >> arr_size;
    int treshold;
    std::cin >> treshold;

    for (int j = 0; j < arr_size; j++) {
      int tmp;
      std::cin >> tmp;
      arr.push_back(tmp);
    }

    std::cout << solve_case(arr, treshold) << std::endl;
  }

  return 0;
}
