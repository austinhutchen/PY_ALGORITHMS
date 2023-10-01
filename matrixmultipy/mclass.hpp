#include <stdexcept>
#pragma ONCE
#include <iostream>
#include <vector>
using namespace std;

class matrixrow {
public:
  matrixrow(void) {
    row = new vector<int>();
    index = 1;
  }
  matrixrow(unsigned size) {
    row = new vector<int>(size);
    index = 1;
  }
  bool safe() { return (index < row->size()); }
  void fill(string in, unsigned start, size_t count) {
    // string now needs parsing
    for (int i = start; i < count; i++) {
      row->push_back(in[i]);
    }
  }

  double xn(size_t i) { return row->at(i - 1); }
  void setelement(int val) {
    // set element i to val.
    row->at(index - 1) = val;
    index++;
    return;
  }
  void setrow(vector<int> nrow) {
    // set element i to val.
    this->row->clear();
    this->row = &nrow;
  }
  void print() {
    // set element i to val.
    vector<int>::iterator r_ptr = this->row->begin();
    while (r_ptr != row->end()) {
      cout << *r_ptr << " , ";
      r_ptr++;
    }
    cout << endl;
  }
  vector<int> *&handoff() { return row; }

private:
  vector<int> *row;
  unsigned index;
};