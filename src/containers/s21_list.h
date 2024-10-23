#ifndef S21_LIST_H_
#define S21_LIST_H_

namespace s21 {

template <class T>
class list {
public:
  using value_type = T;
  using reference = T&;
  using const_reference = cons T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  operator=(list &&l);

  const_reference front();
  const_reference back();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);

protected:
  class ListIterator<T>;
  class ListConstIterator<T>;
  struct Node {
    Node(value_type data = 0, Node *next = nullptr, Node *prev = nullptr) : data_(data), next_(next), prev_(prev) {}
    value_type data_;
    Node *next_;
    Node *prev_;
  };
  
private:
  Node *head_;
  Node *tail_;
  size_type size_;
};

list::list(): head_(new Node()), tail_(head_), size_(0) {}
list::list(size_type n) : list() {
  // добавить по одному элементу push_back
}
list::list(std::initializer_list<value_type> const &items) {
  
}
list::list(const list &l) {}
list::list(list &&l) {}
~list::list() {}

void list::push_back(const_reference value) {
  if (head_ == tail_) {
    tail = new Node(value, tail_)
    tail.next.prev = tail
    head = tail
  } else {
    tail = new Node(value, tail.next, tail // хуита какая-то
  }
  size_++;
}
void list::pop_back() {}
void list::push_front(const_reference value) {}
void list::pop_front() {}
#endif

