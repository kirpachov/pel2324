#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>

int solve_case(std::vector<int> &arr, const int treshold) {
  std::sort(arr.begin(), arr.end());

  int best = 2;

  int best_first = 0;

  for (int i = 0; i < arr.size(); i++) {

    int step = arr.size() - i - 1;
    do {
      step = (step / 2);
    } while (abs(arr.at(i) - arr.at(i + step)) > treshold);

    int first_set_size = step;

    while (i + first_set_size < arr.size() && abs(arr.at(i + first_set_size) - arr.at(i)) <= treshold) {
      first_set_size++;
    }


    if (best_first >= first_set_size) continue;
    else best_first = first_set_size;

    for (int j = i + first_set_size; j < arr.size(); j++) {
      int step = arr.size() - j - 1;
      do {
        step = (step / 2);
      } while (abs(arr.at(j) - arr.at(j + step)) > treshold);

      int second_set_size = step;
      while (j + second_set_size < arr.size() && abs(arr.at(j) - arr.at(j + second_set_size)) <= treshold) {
        second_set_size++;
      }

      if (best < first_set_size + second_set_size) best = first_set_size + second_set_size;
    }
  }

  // std::cout << "a: " << a << std::endl;

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
