struct my_val{
  my_val(int value){
    m_value = value;
  }

  private:
    int m_value;
};

int main(){
  my_val a{5};

  return 0;
}
