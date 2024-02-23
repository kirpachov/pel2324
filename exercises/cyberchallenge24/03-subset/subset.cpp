#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>

int solve_case(std::vector<int> &arr, const int treshold){
	std::sort(arr.begin(), arr.end());


	int best = 2;

	int a = 0;
	int best_first = 0;

	for(int i = 0; i < arr.size(); i++){
		int first_set_size = 0;
		// TODO:
		// here (and in the while below)
		// use binary search mechanism to calculate `first_set_size`
		// much faster.
		while(i + first_set_size < arr.size() && abs(arr.at(i + first_set_size) - arr.at(i)) <= treshold){
			first_set_size++;
		}

		if (best_first >= first_set_size) continue;
		else best_first = first_set_size;
	
		for(int j = i + first_set_size; j < arr.size(); j++){
			int second_set_size = 0;
			while(j + second_set_size < arr.size() && abs(arr.at(j) - arr.at(j + second_set_size)) <= treshold){
				second_set_size++;
				a++;
			}

			if (best < first_set_size + second_set_size) best = first_set_size + second_set_size;
		}

	}

	return best;
}

int main(void){
	size_t scenarios;
	std::cin >> scenarios;
	for(int i = 0; i < scenarios; i++) {
		std::vector<int> arr;
		int arr_size;
		std::cin >> arr_size;
		int treshold;
		std::cin >> treshold;
	
		for(int j = 0; j < arr_size; j++){
			int tmp;
			std::cin >> tmp;
			arr.push_back(tmp);
		}

		std::cout << solve_case(arr, treshold) << std::endl;
	}

	return 0;
}
