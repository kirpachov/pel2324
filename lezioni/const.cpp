#include<iostream>

class IntArray {
  public:
    int *m_arr;
    int m_size;
    IntArray(void){
      m_size = 10;
      m_arr = (int *)malloc(sizeof(int) * m_size);
      std::cout << "Creato" << std::endl;
    }

    /*
    // Compilation error: declared as const but is not const
    void fake_const(void) const {
      m_size++;
    }
    */

    // You can break the "const" promise by using points
    int* at(const int index){
      return m_arr + index;
    }

    const int* at(const int index) const {
      return m_arr + index;
    }

    int* operator[](const int index){
      return m_arr + index;
    }

    void operator!(void){
      std::cout << "Calm down, mate." << std::endl;
    }

    void print() const {
      for(int i = 0; i < m_size; i++){
        std::cout << *(m_arr + i);

        if (i + 1< m_size) std::cout << ", ";
      }

      std::cout << std::endl;
    }
};

void print_first(const IntArray &arr){
  // ERROR:
  // *(arr.at(0)) = 5;

  // *(arr[0]) = 6;

  std::cout << *(arr.at(0)) << std::endl;
}

int main(void){
  IntArray arr;
 
  /*

  // Write element with .at 

  *(arr.at(0)) = 5;

  */

  // Write element with []
  *(arr[0]) = 6;
  
  print_first(arr);

  arr.print();

  // arr!;

  // std::cout << "arr.at(0): " << *arr.at(0) << std::endl;;
   
  return 0;
}
