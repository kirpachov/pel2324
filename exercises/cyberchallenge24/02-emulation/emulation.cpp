#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<size_t, std::string> read_instructions(void){
	size_t instructions_count;
	std::cin >> instructions_count;

	/*
	 * NEXT LINE:
	 * When consuming whitespace-delimited input (e.g. size_t n; std::cin >> n;) any whitespace that follows, including a newline character, will be left on the input stream. Then when switching to line-oriented input, the first line retrieved with getline will be just that whitespace. In the likely case that this is unwanted behaviour, possible solutions include:
	 */
	std::cin >> std::ws;
	std::unordered_map<size_t, std::string> instructions_map;
	for(size_t i = 0; i < instructions_count; i++){
		std::string current;
		std::getline(std::cin, current, '\n');
		instructions_map.insert({i + 1, current});
	}
	

	return instructions_map;
}

/**
 * Split a string in multiple strings based on a delimiter.
 *
 * @return [std::vector<std::string>]
 */
std::vector<std::string> split(std::string const &str, const std::string &delimiter){
	std::vector<std::string> result;

	size_t index = 0;
	while(str.substr(index, str.length()).find(delimiter) != std::string::npos){
		result.push_back(str.substr(index, str.substr(index, str.length()).find(delimiter)));
		index += str.substr(index, str.length()).find(delimiter) + delimiter.length();
	}

	result.push_back(str.substr(index, str.substr(index, str.length()).find(delimiter)));

	return result;
}

long long int calc_sum(std::unordered_map<std::string, long long int> const &data){
	return data.at("a") + data.at("b") + data.at("c") + data.at("d") + data.at("e") + data.at("f");
}

/**
 * This method will apply the effects of a instruction.
 *
 * @return [size_t] next instruction line. current + 1 unless its a branch.
 */
void process_line(size_t &line, const std::string instruction, std::unordered_map<std::string, long long int> &data){
	const std::vector<std::string> parts = split(instruction, " ");

	if (parts.at(0).compare("add") == 0) data.at(parts.at(1)) += std::stoi(parts.at(2));
	else if (parts.at(0).compare("sub") == 0) data.at(parts.at(1)) -= std::stoi(parts.at(2));
	else if (parts.at(0).compare("mul") == 0) data.at(parts.at(1)) *= std::stoi(parts.at(2));
	else if (parts.at(0).compare("lab") == 0) data.insert({ parts.at(1), line });
	else if (parts.at(0).compare("jmp") == 0) { if (data.at(parts.at(1)) == stoi(parts.at(2))) line = data.at(parts.at(3)); }
	else {
		std::cout << "got invalid instruction: '" << parts.at(0) << "'" << std::endl;
		exit(1);
	}

	line = line + 1;
}

int main(void){
	std::unordered_map<size_t, std::string> instructions = read_instructions();

	std::unordered_map<std::string, long long int> data = {{"a", 0}, {"b", 0}, {"c", 0}, {"d", 0}, {"e", 0}, {"f", 0}};

	size_t line = 1;
	do {
		const std::string instruction = instructions.at(line);
		process_line(line, instruction, data);
	} while(line <= instructions.size());

	std::cout << calc_sum(data) << std::endl;

	return 0;
}
