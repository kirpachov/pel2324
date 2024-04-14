#include<iostream>
#include<cassert>


//questa parte andrebbe nel file hpp
class List_dl {

  public:
    List_dl();  //Default constructor 
    List_dl(const List_dl& copy);  //Copy constructor
    ~List_dl();

    void prepend(int elem);
    void append(int elem);

    void remove_elements(int elem);

    List_dl operator+(const List_dl& l) const;
    List_dl& operator=(const List_dl& l);


    void print() const;
    void print_rev() const;

   int& at(int pos);   
   const int& at(int pos) const;

  private:
    struct Impl;
    Impl* pimpl;
};

//questa parte andrebbe nel file cpp

struct Cell {
  int info;
  Cell* next;
  Cell* prev;

  // Metodo che si occuperà di rimuovere this dalla lista.
  void remove_me();
  void remove_me(const bool free_memory);
};

typedef Cell* Pcell;

struct List_dl::Impl {
  Pcell head;
  Pcell tail;
  int dummy;
  void destroy(Pcell head) const;

  // copy the list and return the pointer to the last element, nullptr for the empty list
  Pcell copy(Pcell& dest, Pcell source) const;
};

void Cell::remove_me() {
  remove_me(true);
}

void Cell::remove_me(const bool free_memory){
  if (prev) prev->next = next;
  if (next) next->prev = prev;

  if (free_memory) delete this;
}
  
// Default constructor
List_dl::List_dl() {
  pimpl = new Impl;
  pimpl->head = nullptr;
  pimpl->tail = nullptr;
}

// Copy constructor
List_dl::List_dl(const List_dl& source) {
  pimpl = new Impl;
  pimpl->tail = pimpl->copy(pimpl->head, source.pimpl->head);
}

List_dl::~List_dl() {
  pimpl->destroy(pimpl->head);
  delete pimpl;
}

void List_dl::Impl::destroy(Pcell head) const {
  if (head) {
    destroy(head->next);
    delete head;
  }
}

void List_dl::prepend(int el) {
  Pcell pcell = new Cell;
  pcell->prev = nullptr;
  pcell->info = el;
  pcell->next = pimpl->head;

  if (pimpl->head != nullptr) pimpl->head->prev = pcell;
  else pimpl->tail = pcell;

  pimpl->head = pcell;
}

void List_dl::append(int el) {
  Pcell pcell = new Cell;
  pcell->next = nullptr;
  pcell->info = el;
  pcell->prev = pimpl->tail;

  if (pimpl->tail != nullptr) pimpl->tail->next = pcell;
  else pimpl->head = pcell;

  pimpl->tail = pcell;
}

void List_dl::print() const {
  Pcell pc = pimpl->head;
  while (pc) {
    std::cout << pc->info << std::endl;
    pc = pc->next;
  }
}

void List_dl::print_rev() const {
  Pcell pc = pimpl->tail;
  while (pc) {
    std::cout << pc->info << std::endl;
    pc = pc->prev;
  }
}


// deep copy the list from source to dest and return the pointer to the last element of the list
// pointed by dest, nullptr for the empty list
Pcell List_dl::Impl::copy(Pcell& head, Pcell source) const {
  Pcell tail = nullptr;
  head = nullptr;

  while(source){
    Pcell current = new Cell;
    current->info = source->info;
    current->next = nullptr;
    current->prev = tail;

    if (tail) {
      tail->next = current;
    }

    if (!head) head = current;

    tail = current;

    source = source->next;
  }

  return tail;
}

/*Returns the element in position pos. If pos>=0 then the
 * positions are counted from head starting by 0
 * if pos < 0 then we count from tail backword. Hence the last
 * position is -1, the one before -2 and so on
 * If pos is not in the list, return the dummy int present in struct pimpl
 */

int& List_dl::at(int pos) {
    if (pos == 0) {
      if (pimpl->head) return pimpl->head->info;
      return pimpl->dummy;
    }

    if (pos > 0){
      Pcell h = pimpl->head;
      while(pos > 0 && h){
        h = h->next;
        pos--;
      }

      // Correct case: element found. returning value.
      if (pos == 0 && h) return h->info;

      // element not found.
      return pimpl->dummy;
    }

    // case pos < 0
    Pcell t  = pimpl->tail;
    while(pos < -1 && t){
      t = t->prev;
      pos++;
    }

    if (pos == -1 && t) return t->info;

    return pimpl->dummy;
}

const int& List_dl::at(int pos) const {
    if (pos == 0) {
      if (pimpl->head) return pimpl->head->info;
      return pimpl->dummy;
    }

    if (pos > 0){
      Pcell h = pimpl->head;
      while(pos > 0 && h){
        h = h->next;
        pos--;
      }

      // Correct case: element found. returning value.
      if (pos == 0 && h) return h->info;

      // element not found.
      return pimpl->dummy;
    }

    // case pos < 0
    Pcell t  = pimpl->tail;
    while(pos < -1 && t){
      t = t->prev;
      pos++;
    }

    if (pos == -1 && t) return t->info;

    return pimpl->dummy;
}

/* Assignment with deep copy */
List_dl& List_dl::operator=(const List_dl& l) {
  if (this == &l) return *this; // protect from self-assignment 

  // copied from List_dl copy constructor
  pimpl = new Impl;
  pimpl->tail = pimpl->copy(pimpl->head, l.pimpl->head);

  return *this;
}

/*This operator concatenates the two list (*this first and l follows)*/
List_dl List_dl::operator+(const List_dl& l) const {
  List_dl result = *this;

  // copied from List_dl::Impl::copy
  Pcell tail = result.pimpl->tail;
  Pcell source = l.pimpl->head;

  while(source){
    Pcell current = new Cell;
    current->info = source->info;
    current->next = nullptr;
    current->prev = tail;

    if (tail) {
      tail->next = current;
    }

    if (!(result.pimpl->head)) result.pimpl->head = current;

    tail = current;

    source = source->next;
  }

  result.pimpl->tail = tail;

  return result;
}


/* Remove all the elements equal to elem */
void List_dl::remove_elements(int elem) {
  Pcell h = pimpl->head;
  Pcell next = nullptr;

  while(h){
    next = h->next;

    if (h->info == elem) h->remove_me();

    h = next;
  }
}

/*copy and paste from the previous exercise*/

//Test copy constructor and at

void modify(List_dl lin) {
  int pos, value;
  for (int i=0; i<3; i++) {
    std::cin>>pos;
    std::cin>>value;
    lin.at(pos)=value;
  }
  lin.print();
  lin.print_rev();
}


int main() {
  int x;
  List_dl l;
  do {
    std::cin>>x;
    if (x!=0)
      l.append(x);
  } while (x!=0);

  modify(l);  //Whoops call the copy constructor!

  l.print();
  l.print_rev();
}
