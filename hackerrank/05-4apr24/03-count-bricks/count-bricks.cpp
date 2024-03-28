#include <iostream>
#include <cassert>

int conta_mattoncini(const int n){
    assert(n > 0);
    if (n == 1) return 1;

    return n + conta_mattoncini(n % 2 == 0 ? n / 2 : n - 1);
}

int main(void) {
    int base;
    std::cin>>base;

    std::cout << conta_mattoncini(base) << std::endl;

    return 0;
}

