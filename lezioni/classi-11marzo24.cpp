#include<iostream>

class Point {
  public:
    /* Default constructor */
    Point() {
      x = 0.0;
      y = 0.0;
    }
    
    // Common constructor
    Point(double new_x, double new_y){
      x = new_x;
      y = new_y;
    }

    // Constructor overloading
    Point(double new_x) {
      x = new_x;
      y = 0.0;
    }
    
    Point(double new_x, double new_y, std::string new_point_name){
      x = new_x;
      y = new_y;
      point_name = new_point_name;
    }
    
    // Copy constructor
    Point(const Point &orig){
      
    }

    // DESTRUCTOR
    ~Point(){
      // std::cout << "terminator!!!" << std::endl;
    }

    // Instance methods
    void log(){
      std::cout << "x: " << x << " y: " << y;
      if (point_name.length() > 0) std::cout << " " << point_name;

      std::cout << std::endl;
    }

    void set_x(double new_x){ x = new_x; }
    void set_y(double new_y){ y = new_y; }

  private:
    double x;
    double y;
    std::string point_name;
};

int main(void){
  /**
    Il meccanismo pubblico/privato si chiama incapsulamento.

    un "metodo":
    - ha accesso a tutti i suoi parametri formali, come le funzioni
    - può accedere alla parte privata della classe in cui è definito.

    Una definizione è una dichiarazione che alloca memoria.
   
    !!! 
    Utilizzare costrutture con le graffe, non con le tonde!!!
    Il costruttore con le graffe verifica che non avvenga narrowing.
  */
  Point a;
  a.log();
  a.set_x(22);
  a.set_y(92);
  a.log();

  Point b(11, 45);
  b.log();

  Point c(35);
  c.log();

  Point d{1, 2, "Banana"};
  d.log();
  
  return 0;
}
