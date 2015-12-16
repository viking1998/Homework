#include<iostream>
using namespace std;

enum Direction {
  UP = 1,
  RIGHT = 1 << 1,
  DOWN = 1 << 2,
  LEFT = 1 << 3
};

class Cell {
  int row_, col_;
  bool visited_;
  int walls_;
  
  public:
  
  Cell(int row, int col) : visited_(false), row_(row), col_(col), walls_(UP | RIGHT | DOWN | LEFT) 
  {}
  
  void drill(Direction dir) {
    //dir = 1000
    //~dir = 0111
    //walls_ = 1111
    //walls_ & ~dir = 0111
    walls_ &= ~dir;
  }
  
  bool has_wall(Direction dir) {  
    return walls_ & dir;
  }
  
  void draw(int length) {
    cout << row_*length << " " << col_*length << " moveto" << endl;
    cout << 0 << " " << -length << (has_wall(DOWN) ? " rlineto" : " rmoveto") << endl;
    cout << length << " " << 0 << (has_wall(RIGHT) ? " rlineto" : " rmoveto") << endl;
    cout << 0 << " " << length << (has_wall(UP) ? " rlineto" : " rmoveto") << endl;
    cout << -length << " " << 0 << (has_wall(LEFT) ? " rlineto" : " rmoveto") << endl;
  }
};

class Board {

};

int main() {
  cout << "newpath" << endl;
  Cell c1(4, 4);
  c1.drill(DOWN);
  c1.draw(20);
  cout << "stroke" << endl;
  return 0;
}
