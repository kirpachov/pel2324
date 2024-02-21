#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>


std::vector<std::string> read_instructions(void){
	int instructions_count;
	std::cin >> instructions_count;
	std::cout << "Got " << instructions_count << " instructions\n";

	std::vector<std::string> instructions;
	for(int i = 0; i < instructions_count; i++){
		std::string current;
		std::getline(std::cin, current);
		instructions.push_back(current);
	}

	/*
	std::cout << "Instructions:\n";
	for(int i = 0; i < instructions_count; i++){
		std::cout << instructions.at(i) << "\n";
	}
	*/
	

	return instructions;
}

void print_hashmap(std::unordered_map<std::string, int> hashmap){
        for (const auto &p : hashmap) {
                std::cout << p.first << '\t' << p.second << std::endl;
        }
}

int main(void){
	std::vector<std::string> instructions = read_instructions();

	// Data memory
	std::unordered_map<std::string, int> data = {{"a", 0}, {"b", 0}, {"c", 0}, {"d", 0}, {"e", 0}, {"f", 0}};

	print_hashmap(data);

	return 0;
}
