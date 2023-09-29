#pragma ONCE
#include <iostream>
#include <vector>
using namespace std;

class matrixrow {
  public:
  matrixrow(void) { row = new vector<double>(); }
  matrixrow(unsigned size) { row = new vector<double>(size); }

  void fill(string in, unsigned start, size_t count) {
    // string now needs parsing
    for (int i = start; i < count; i++) {
      row->push_back(in[i]);
    }
  }
  double xn(size_t i){
    return row->at(i-1);
  }
  void setelement(size_t i, double val){
    // set element i to val.
    row->at(i-1)=val;
    return ;
  }
private:
  vector<double> *row;
};