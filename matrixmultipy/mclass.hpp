#pragma ONCE
#include <iostream>
#include <vector>
using namespace std;

class matrixrow {
  public:
  matrixrow(void) { row = new vector<int>(); }
  matrixrow(unsigned size) { row = new vector<int>(size); }

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
  void setrow (vector<int> nrow){
    // set element i to val.
    delete this->row;
    this->row=&nrow;
  }
  vector<int> * handoff(){
    return row;
  }
private:
  vector<int> *row;
};