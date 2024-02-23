#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//#include <cstdlib>
#include <chrono>

/**
 * Will return the index of the biggest value <= of looking_for.
 */
/*
int find_el(std::vector<int> &vector, const int look_from, const int look_to, const int looking_for){
	assert(look_from >= 0);
	assert(look_to < vector.size());

	if (look_to == look_from) return look_to;

	int middle = look_from + ((look_to - look_from) / 2);
	if (vector.at(middle) == looking_for) return middle;

	std::cout << "look_from: " << look_from
		  << "\tlook_to: " << look_to
		  << "\tmiddle: " << middle
		  << "\tvector.at(middle): " << vector.at(middle)
		  << "\tlooking_for: " << looking_for
		  << std::endl;

	if (look_from == 3) return 0;

	if (vector.at(middle) > looking_for) return find_el(vector, look_from, middle, looking_for);

	return find_el(vector, middle, look_to, looking_for);
}*/

int solve_case(std::vector<int> &arr, const int treshold){
//	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	std::sort(arr.begin(), arr.end());

//	std::chrono::steady_clock::time_point after_sort = std::chrono::steady_clock::now();
	//std::cout << "after_sort: " << std::chrono::duration_cast<std::chrono::microseconds>(after_sort - begin).count() << "[µs]" << std::endl;

	int best = 2;

	int a = 0;
	int best_first = 0;

	for(int i = 0; i < arr.size(); i++){
		int first_set_size = 0;
		while(i + first_set_size < arr.size() && abs(arr.at(i + first_set_size) - arr.at(i)) <= treshold){
			first_set_size++;
		}
		//const int found = find_el(arr, i, arr.size() - 1, arr.at(i) + treshold);
		//std::cout << "first_set_size: " << first_set_size << "\tfind_el: " << found << std::endl;

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

	//std::cout << "a: " << a << std::endl;

	//std::chrono::steady_clock::time_point done = std::chrono::steady_clock::now();
	//std::cout << "done: " << std::chrono::duration_cast<std::chrono::microseconds>(done - begin).count() << "[µs]" << std::endl;

	return best;
}

int main(void){
	/*std::vector<int> arr = {1,2,3,4,5};
	int found = find_el(arr, 0, 4, 5);
	std::cout << found << std::endl;
	return 0;
	*/

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
