#include<iostream>
#include<vector>
#include<cassert>

class Primes{
  private:
    std::vector<int> numbers;

    bool is_prime(const int num) const {
      assert(num > 1);

      bool is_prime = true;
      for(int i = 2; i < (num / 2) + 1; i++){
        if (num % i == 0) is_prime = false;
      }

      return is_prime;
    }

    int next_prime(int num) const {
      bool found = false;
      do {
        num++;
        found = is_prime(num);
      } while (!found);

      return num;
    }


    void fill_with_primes(int size) {
      // If I already have the necessary prime number inside my vector, do nothing.
      // Otherwise ...
      if (numbers.size() >= size) return;

      // ... will add all the necessary prime numbers inside the vector.
      int last_prime = numbers.size() > 0 ? numbers.at(numbers.size() - 1) : 2;

      while(numbers.size() < size){
        numbers.push_back(last_prime);

        // May be doing one call more than needed.
        last_prime = next_prime(last_prime);
      }
    }

  public:
    Primes(int size) {
      // No need to innitialize our primes, we'll do everything runtime.
      // Since we are going to call "fill_with_primes" anyway inside "get_prime",
      // There's no valid reason to call it inside the inizializer: I risk to create a 
      // vector that I may not need.
    }

    int get_prime(int index) {
        fill_with_primes(index + 1);
        return numbers.at(index);
    }
};

int main() {
  int size, n;
  std::cin>>size;
  std::cin>>n;

  Primes p(size);

  std::cout<<p.get_prime(n);

  return 0;
}


