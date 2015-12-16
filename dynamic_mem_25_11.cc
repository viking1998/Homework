#include<cstdlib>

class Static {
  int array[20];
  int number_;
  
  public:
  
  Static(int i = 10) {
    number_ = i;
  }

};

int main() {
  Static* st = new Static(20);
  Static* st_array = new Static[20];
  
  delete st;
  delete [] st_array;
  
  return 0;
}
