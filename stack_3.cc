#include <iostream>
using namespace std;

class StackError {
  int status_;
  public:
    StackError(int status) {
      status_ = status;
    }
    
    int get_status() {
      return status_;
    }
};

class Stack {
  int* data_;
  int top_;
  int size_;
  static const int chunk_ = 2;
  
  public:
    Stack(int size = 2) {
      top_ = 0;
      size_ = size;
      data_ = new int[size_];
    }
    
    ~Stack() {
      cout << "calling destructor...." << endl;
      delete [] data_;
    }
    
    Stack(const Stack& other) {
      cout << "calling copy constructor..." << endl;
      top_ = other.top_;
      size_ = other.size_;
      data_ = new int[size_];
      for(int i = 0; i < top_; i++) {
        data_[i] = other.data_[i];
      }
    }
    
    bool is_empty() {
      return top_ == 0;
    }
    
    bool is_full() {
      return top_ == size_;
    }
    
    void push(int val) {
      if(is_full()) {
        resize();
      }
      data_[top_++] = val;
    }
    int pop() {
      if(is_empty()) {
        cout << "OOOPS: stack is empty..." << endl;
        throw StackError(2);
      }
      return data_[--top_];
    }
    
    private:
    
    void resize() {
      size_ += chunk_;
      int* temp = data_;
      data_ = new int[size_];
      for(int i = 0; i < top_; i++) {
        data_[i] = temp[i];
      } 
      delete [] temp;
    }
};

void function(Stack& st) {
  cout << "pop from function " << st.pop() << endl;
  cout << "pop from function " << st.pop() << endl;
  st.push(100);
}

int main() {
  Stack st(100);
  for(int i=0; i<100; i++) {
      st.push(i);
    }
  function(st);
  
  cout << "calling main pop:  " << st.pop() << endl;
  return 0;
}
