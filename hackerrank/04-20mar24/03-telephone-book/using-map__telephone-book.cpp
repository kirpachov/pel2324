#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<cassert>
#include <cstring>

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

// Given a string, will return a string without space on beginning.
// E.g. " a bc de f " => "a bc de f"
std::string remove_start_space(const std::string &str){
  int index = 0;
  while(index < str.size() - 1 && str.at(index) == ' ') index++;

  return str.substr(index, str.size() - index);
}

void capitalize_first_letters(std::string & str){
  for(int i = 0; i < str.size(); i++){
    int code = str.at(i);

    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)){
      const bool is_upper = code <= 90;
      const bool should_be_upper = (i == 0) || (i > 0 && str.at(i - 1) == ' ');
    
      if (is_upper && !should_be_upper) str.at(i) = tolower(str.at(i));
      else if (!is_upper && should_be_upper) str.at(i) = toupper(str.at(i));
    }
  }
}

std::string remove_end_space(const std::string &str){
  int index = str.size() - 1;
  while(index > 0 && str.at(index) == ' ') index--;

  return str.substr(0, index + 1);
}

std::string trim(const std::string & str){
  return remove_end_space(remove_start_space(str));
}

std::string remove_trailing(const std::string & str, const char ch){
  if (str.at(str.size() - 1) == ch) return str.substr(0, str.length() - 1);

  // Returning a copy of the original str.
  return std::string{str};
}

class Contatto {
  private:
    std::string format_fullname(std::string str) const {
      // Remove whitespace before and after.
      str = trim(str);

      // Remove double spaces
      str = std::regex_replace(str, std::regex("\\s{2,}"), " ");

      // Lowercase all, capitalize first letters.
      capitalize_first_letters(str);

      return str;
    }

    std::string format_cellphone(std::string str) const {
      str = std::regex_replace(str, std::regex("\\s{1,}"), "");
      if (str.size() < 10) return std::string{"numero non valido"};
      
      std::string prefix = str.substr(0, str.size() - 10);
      if (prefix.size() == 0) prefix = std::string{"39"};
      if (prefix.at(0) != '+') prefix = std::string{"+"} + prefix;

      str = str.substr(str.size() - 10, 3) + " " + str.substr(str.size() - 7, 3) + " " + str.substr(str.size() - 4, 4);

      return prefix + " " + str;
    }

  public:
    std::string m_fullname;
    std::string m_cellphone;

    Contatto(const std::string &bad_fullname, const std::string& bad_cellphone){
      m_fullname = format_fullname(bad_fullname);
      m_cellphone = format_cellphone(bad_cellphone);
    }
};

class Rubrica {
  private:
    // Will read input and save contacts locally
    void save_contacts(const std::string & input){
      const std::vector<std::string> parts = split(remove_trailing(trim(input), ','), std::string{","});
      assert(parts.size() % 2 == 0); // For each fullname we must have a cellphone.
      
      m_contacts = {};
      for(int i = 0; i < parts.size(); i += 2) {
        const Contatto c{parts.at(i), parts.at(i + 1)};
        m_contacts.insert({c.m_fullname, c});
      }
    }

    // Will order contacts by name.
    void order_contacts(){
/*
      bool changes_made;
      do {
        changes_made = false;
        for(int i = 0; i < m_contacts.size() - 1; i++){
          if (order_swap_strings(m_contacts.at(i).fullname, m_contacts.at(i + 1).fullname)) {
            changed_made = false;
            const Contact c = m_contacts.at(i);
            m_contacts.at(i) = m_contacts.at(i + 1);
          }
        }
      } while (changes_made);*/
    }

  public:
    std::map<std::string, Contatto> m_contacts;
    Rubrica(const std::string& str) {
      save_contacts(str);
      order_contacts();
    }

    void stampa_contatti_ordinati() {
      // for(auto contact: m_contacts) std::cout << contact.m_fullname << ": " << contact.m_cellphone << std::endl;
      for(const auto& [_key, contact] : m_contacts) std::cout << contact.m_fullname << ": " << contact.m_cellphone << std::endl;
    }
};

int main() {
   std::string input;
   getline(std::cin, input);
   Rubrica r(input);
   r.stampa_contatti_ordinati();
   return 0;
}
