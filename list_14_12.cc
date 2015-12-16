#include<iostream>
using namespace std;

class ListError {};

class List {
  class Node {
    friend class List;
    int data_;
    Node* next_;
    Node* prev_;
    
    Node(int data) : data_(data), next_(0), prev_(0) {}
  };

  Node* head_;
  
  public:
  
  List() : head_(new Node(0)) {
    head_->next_ = head_;
    head_->prev_ = head_;    
  }
  
  bool empty()
  {
      return head_->next_ == head_;
  }
  
  void push_back(int value)
  {
    Node* new_node = new Node(value);
    Node* last = head_->prev_;
    new_node->next_ = head_;
    new_node->prev_ = last;
    last->next_ = new_node;
    head_->prev_ = new_node;
  }
  
  void push_front(int value) {
    Node* new_node = new Node(value);
    Node* first = head_->next_;
    
    new_node->prev_ = head_;
    new_node->next_ = first;
    
    first->prev_ = new_node; 
    head_->next_ = first; 
  }
  
  
  class Iterator {
    friend class List;
    Node* ptr_;
    
    Iterator(Node* ptr) : ptr_(ptr) {}
    public:
    Iterator& next() {
      ptr_ = ptr_->next_;
      return *this;
    }
    
    Iterator& prev() {
      ptr_ = ptr_->prev_;
    }
    
    int& operator*() {
      return ptr_->data_;
    }
  };
  
  Iterator begin() {
    return Iterator(head_->next_);
  }
  
  Iterator end() {
    return Iterator(head_);
  }
};

int main() {
  
  List list;
  cout << list.empty() << endl;
  list.push_back(12);
  cout << list.empty() << endl;
  list.push_back(23);
  List::Iterator it = list.begin();
  //cout <<  << endl;
  return 0;
}
