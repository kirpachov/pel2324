#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_bad_words(void){
  int banned_size;
  std::cin >> banned_size;

  std::vector<std::string> bad_words;
  for (int i = 0; i < banned_size; i++) {
    std::string current;
    std::cin >> current;
    bad_words.push_back(current);
  }

  return bad_words;
}

int main(void) {
  int checks_size;
  std::cin >> checks_size;

  std::vector<std::string> bad_words = read_bad_words();

  for (int i = 0; i < checks_size; i++) {
    std::string current;
    std::cin >> current;
    bool is_bad = false;

    for (const std::string &bad_word: bad_words){
      if (current.find(bad_word) != std::string::npos) is_bad = true;
    }

    std::cout << (is_bad ? "BANNED" : "SAFE") << "\n";
  }

  return 0;
}
