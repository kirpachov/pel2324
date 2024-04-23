#include <iostream>
#include<cassert>

class circ_list{
  public:
    circ_list(){ tail = nullptr; } // costruttore default
    circ_list(const circ_list& copy); // costruttore per copia
    // distruttore di default
    ~circ_list() {
        if(tail != nullptr){
            pcella head = tail->next;
            tail->next = nullptr;
            tail = head;

            while(head != nullptr)
            {
                tail = tail->next;
                delete head;
                head = tail;
            } 
        }
    }
    void append(int el) {
        pcella nuovo = new Cella;
        nuovo->info = el;
        if (tail==nullptr) {
            nuovo->next = nuovo;
            tail = nuovo;
        }
        else {
            nuovo->next = tail->next;
            tail->next = nuovo;

            tail = tail->next;
        }
    }
    void prepend(int el) {
        pcella nuovo = new Cella;
        nuovo->info = el;
        if (tail==nullptr) {
            nuovo->next = nuovo;
            tail = nuovo;
            return;
        }
        nuovo->next = tail->next;
        tail->next = nuovo;
    }
    void stampa_lista() const {
        if (tail) {
            pcella head = tail->next;
            do {
                std::cout << head->info << " ";
                head = head->next;
            } while (tail->next!=head);
        }
        std::cout<<std::endl;
    }
    int size() const {
      int acc = 0;
      if (tail) {
        pcella head = tail->next;
        do {
          acc++;
          head = head->next;
        } while (tail->next!=head);
      }
      return acc;
    }
    int sum() const {
      int acc = 0;
      if (tail) {
        pcella head = tail->next;
        do {
          acc += head->info;
          head = head->next;
        } while (tail->next!=head);
      }
      return acc;
    }
    void split_list(circ_list& fh, circ_list& sh) const;
  private:
    struct Cella {
        int info;
        Cella* next;
    };
    typedef Cella* pcella;
    // ultima cella inserita nella lista
    pcella tail;
};

//leggi lista
void leggi_lista(circ_list& l) {
    int elem, n;
    std::cin>>n;
    while (n>0) {
        std::cin>>elem;
        l.append(elem);
        n--;
    }
}

void circ_list::split_list(circ_list& fh, circ_list& sh) const {
  const int length = size();
  int i = 0;
  pcella middle = nullptr; // will set inside the loop

  if (tail) {
    pcella head = tail->next;
    do {
      if (length % 2 == 1) {
        // Numero di celle dispari.
        if (i < length/2) fh.append(head->info);
        else if ((length/2) == i) {
          assert(middle == nullptr);
          middle = head;
        } else sh.append(head->info);
      } else {
        // Numero di celle pari.
        if (i < (length / 2)) fh.append(head->info);
        else sh.append(head->info);
      }

      head = head->next;
      i++;
    } while (tail->next!=head);
  }

  if (!middle) return;

  if (fh.sum() < sh.sum()) {
    fh.append(middle->info);
    return;
  }

  sh.prepend(middle->info);
}

int main() {
    
    circ_list l;
    leggi_lista(l);

    circ_list l1;
    circ_list l2;
    l.split_list(l1,l2);

    std::cout << "Lista 1: ";
    l1.stampa_lista();
    std::cout << "Lista 2: ";
    l2.stampa_lista();
  
  return 0;
}
