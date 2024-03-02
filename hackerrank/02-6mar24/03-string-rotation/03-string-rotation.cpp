#include <iostream>
#include <string>

using std::string;

bool rotazione(const string& S, const string& T)
{
    // Casi limite:
    if (S.length() != T.length()) return false;
    if (S == T) return true;

    bool is_rotation = false;
    int rotations_made = 0;
    string rotated = T;

    while(!is_rotation && rotations_made < S.length()){
      char first = rotated.at(0);
      rotated = rotated.substr(1, rotated.length() - 1) + first;
      if (rotated == S) is_rotation = true;
      rotations_made++;
    }

    return is_rotation;
}

int main() {
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);
    
    if (rotazione(a,b))
        std::cout << "Si" <<std::endl;
    else
        std::cout << "No" <<std::endl;
        
    return 0;
}
