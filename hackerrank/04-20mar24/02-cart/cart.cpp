#include <iostream>
#include <vector>
#include <string>

class Prodotto {
  public:
    std::string description;
    int quantity;
    double price;

    Prodotto(const std::string& _desc, const int _quantity, const double _price){
      description = _desc;
      quantity = _quantity;
      price = _price;
    }
};

class Carrello{
  private:
    std::vector<Prodotto> products;
    double current_total;

  public:
      Carrello() {
        current_total = 0;
      }
    
      ~Carrello() {}

      // Returning product id
      int add(const std::string & _desc, const int _qnt, const double _cost) {
        products.push_back(Prodotto{_desc, _qnt, _cost});
        current_total += (_cost * _qnt);

        return products.size();
      }

      std::string print_carrello() {
        if (products.size() == 0) return "Carrello vuoto";

        std::string result;
        const std::string separator{", "};
        for(int i = 0; i < products.size(); i++){
            for(char c: products.at(i).description) result.push_back(c);

            if (i + 1 < products.size()) for(char c: separator) result.push_back(c);
        }
        
        return result;
      }

      double total() {
        // Return already calculated value in order to avoid useless calculations
        return current_total;
      }
};

int main() {
	Carrello car;
 
	int items;

	std::cin >> items;

	for (int i=0; i < items; i++) {
		std::string s;
		int q;
		double c;
		std::cin >> s;
		std::cin >> q;
		std::cin >> c;

		car.add(s, q, c);
	}

	std::cout << car.print_carrello();
	std::cout << std::endl;
	std::cout << car.total();
	return 0;
}
