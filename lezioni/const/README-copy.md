Che differenza c'è al livello di Assembly tra una variabile "const" e una no?

> Compila il .cpp in assembly con
```bash
g++ -S consts.cpp -o consts.s
```

# Caso 1: due interi.
Che differenza c'è tra
```cpp
int main(){
  const int a = 5;
  return 0;
}
```

e 
```cpp
int main(){
  int a = 5;
  return 0;
}
```

I due file compilati in assembly non hanno alcuna differenza.

# Caso due: due classi.
Che differenza c'è tra
```cpp
struct my_val{
  my_val(int value){
    m_value = value;
  }

  private:
    int m_value;
}

int main(){
  my_val a{5};

  return 0;
}
```

