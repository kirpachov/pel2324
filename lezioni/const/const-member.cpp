#include<iostream>

/**
  MORALE:
  viene chiamato sempre il metodo non-const tranne quando strettamente necessario.

  viene chiamato il metodo const solo quando l'oggetto è const.
*/

template <typename T>
struct vector{
  vector(){
    initialize();
  }

  void push(const T& a){
    std::cout << "push " << a << std::endl;

    // std::cout << "m_head " << m_head << std::endl;
    if (m_head == nullptr){
      m_head = new T;
    }
    // std::cout << "m_head " << m_head << std::endl;

    m_head[m_size] = a;

    m_size++;
    // m_size - 1;
  }

  int size() const {
    return m_size;
  }

  /*
  friend std::ostream& operator<<(std::ostream& os, const vector<T> v) const {
    int i = 0;
    // while(i < v.size()) os << v.at(i
    // TODO print all vector to os
    return os;
  }*/

  const T& at(const int index) const {
    std::cout << " [const at(" << index << ")] ";
    return m_head[index];
  }

  T& at(const int index) {
    std::cout << " [at(" << index << ")] ";
    return m_head[index];
  }

  private:
    T* m_head;
    int m_size;

    void initialize(){
      m_size = 0;
      m_head = nullptr;
    }
};

void get_vector(vector<int> &v1){
  v1.at(0);
}

void get_const_vector(vector<int> const &v1){
  v1.at(0);
}

int main(void){
  vector<int> v;

  std::cout << "pushing 15" << std::endl;
  v.push(15);
  std::cout << "\n\n";

  std::cout << "writing with at(<index>)=" << std::endl;
  v.at(0) = 12;
  std::cout << "\n\n";

  std::cout << "calling get_vector" << std::endl;
  get_vector(v);
  std::cout << "\n\n";

  std::cout << "calling get_const_vector" << std::endl;
  get_const_vector(v);
  std::cout << "\n\n";

  std::cout << "need a value to assign to a const" << std::endl;
  const int const_value = v.at(0);
  std::cout << "const_value is: " << const_value << "\n\n";

  std::cout << "copying first value to local variable in order. When updating local variable, will the value inside the vector change?" << std::endl;
  int local = v.at(0);
  std::cout << "before change | local: " << local << " | v.at(0): << " << v.at(0) << std::endl;
  local = 99;
  std::cout << "after change | local: " << local << " | v.at(0): << " << v.at(0) << std::endl;
  std::cout << "\n\n";

  std::cout << "a: " << v.at(0) << std::endl;
  // std::cout << "v.at(0): " << v.at(0) << std::endl;

  return 0;
}
