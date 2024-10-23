#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <initializer_list>

namespace s21 {

template <class value_type>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = cons T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  operator=(list && l);

  // const_reference front();
  // const_reference back();
  // const_iterator cbegin() const;
  // const_iterator cend() const;

  bool empty();
  size_type size();
  // size_type max_size();

  // void clear();
  // iterator insert(iterator pos, const_reference value);
  // void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  // void swap(list &other);

 protected:
  class ListIterator<value_type>;
  class ListConstIterator<value_type>;
  struct Node {
    Node(value_type data = 0, Node *next = nullptr, Node *prev = nullptr)
        : data(data), next(next), prev(prev) {}
    value_type data;
    Node *next;
    Node *prev;
  };

 private:
  Node *head_;
  Node *tail_;
  size_type size_;
};

template <class value_type>
class list<value_type>::ListIterator<value_type> {
 public:
  ListIterator();
  // ListIterator(Node *iter);
  // ListIterator(const ListIterator &other) = default;
  // ListIterator &operator=(const ListIterator &other);
  // reference operator*();
  // ListIterator &operator++();
  // ListIterator &operator--();
  // bool operator==(const ListIterator &other) const;
  // bool operator!=(const ListIterator &other) const;
  // Node *getNode() const;

  //  private:
  //   Node *iter_;
};

template <class value_type>
inline list<value_type>::list() : head_(new Node()), tail_(head_), size_(0) {
  tail_->next = tail_;
}

template <class value_type>
inline list<value_type>::list(size_type n) {
  // добавить по одному элементу push_back
}

template <class value_type>
inline list<value_type>::list(std::initializer_list<value_type> const &items) {}

template <class value_type>
inline list<value_type>::list(const list &l) {}

template <class value_type>
inline list<value_type>::list(list &&l) {}

template <class value_type>
inline list<value_type>::~list() {}

template <class value_type>
inline list<value_type>::operator=(list && l) {}

template <class value_type>
inline bool list<value_type>::empty() {
  return bool(size_);
}

template <class value_type>
inline size_type list<value_type>::size() {
  return size_;
}

template <class value_type>
inline void list<value_type>::push_back(const_reference value) {
  if (!size_) {
    Node *new_node = new Node(value, tail_);
    tail_->prev = new_node;
    head_ = tail_ = new_node;
  } else {
    Node *new_node = new Node(value, tail_->next, tail_);
    tail_->next = new_node;
    tail_ = new_node;
  }
  size_++;
}

template <class value_type>
inline void list<value_type>::pop_back() {}

template <class value_type>
inline void list<value_type>::push_front(const_reference value) {}

template <class value_type>
inline void list<value_type>::pop_front() {}

template <class value_type>
inline list<value_type>::ListIterator<value_type>::ListIterator() {}

}  // namespace s21
#endif
