#include<iostream>
#include<string>
#include<vector>

/**
  This function will take a string and return the length of the shortest pattern that will repeat in all the string.
  Will be really easy to calculate how many times the pattern will repeat:
  length_of_initial_string / length_pattern.

  Example 1. string is "ababab". Will return 2: "ab" is the smallest pattern.
*/

int smallest_pattern(std::string string){
  if (string.length() <= 1) return 1;
  if (string.length() == 2) return string.at(0) == string.at(1) ? 1 : 2;

  // /2 ???
  for(int i = string.length() - 1; i > 0; i--){
    if (string.length() % i != 0) continue;

    int piece_size = string.length() / i;
    std::string i_str = string.substr(0, piece_size);
    
    for(int j = 1; j < string.length() / piece_size; j++){
      std::string j_str = string.substr(piece_size * j, piece_size);

      if (i_str != j_str) j = string.length() / piece_size;
      else if (j == i - 1) return smallest_pattern(i_str);
    }
  }

  return string.length();
}

/*
int smallest_pattern(const std::string &str){
  if (str.length()  % 2 != 0) return str.length();

  std::string first_part = str.substr(0, str.length() / 2);
  std::string second_part = str.substr(str.length() / 2, str.length() - 1);


  std::cout << "first_part: " << first_part << std::endl;
  std::cout << "second_part: " << second_part << std::endl;

  if (first_part == second_part) return smallest_pattern(first_part.substr(0, first_part.length() / 2));

  return str.length();
}*/

/*
void print_vector(std::vector<std::string> const &vec){
  for(int i = 0; i < vec.size(); i++){
    std::cout << vec.at(i);

    if (i + 1 < vec.size()) std::cout << ", \t";
  }

  std::cout << std::endl;
}

void print_vector(std::vector<std::string> const &vec, const std::string &label){
  std::cout << label << ": \t";
  print_vector(vec);
}

int solve_case(std::string const &alphabet, std::string const &str){
  print_vector(alphabet, "alphabet");
  print_vector(str, "str");

  return 0;
}
*/


/*
int main(void){
  int cases;
  std::cin >> cases;
  for(int i = 0; i < cases; i++){
    std::string trash;
    std::getline(std::cin, trash, '\n');

    std::string alphabet;
    std::getline(std::cin, alphabet, '\n');

    std::string str;
    std::getline(std::cin, str, '\n');
  
    std::cout << solve_case(alphabet, str) << std::endl;  
  }

  return 0;
}*/

void test_smallest_pattern(const std::string &input, const int expected){
  const int actual = smallest_pattern(input);
  if (actual == expected) return;

  std::cout << "Test failed for input '" << input << "'. got " << actual << std::endl;
}

int main(void){
  /*
  test_smallest_pattern("ababab", 2);
  test_smallest_pattern("abcabc", 3);
  test_smallest_pattern("bbbbbb", 1);
  test_smallest_pattern("abc", 3);
  test_smallest_pattern("abcabcabc", 3);
  test_smallest_pattern("abcabcab", 8);
  test_smallest_pattern("cccaaa", 6);
  test_smallest_pattern("babacc", 6);
  test_smallest_pattern("ababc", 5);
  test_smallest_pattern("wassawassa", 5);  
  test_smallest_pattern("qwertyuiop", 10);
  */

  std::string in;
  std::getline(std::cin, in);
  
  std::cout << smallest_pattern(in) << std::endl;
  //test_smallest_pattern(in, 2);

  // test_smallest_pattern("123456", 1);
  return 0;
}
