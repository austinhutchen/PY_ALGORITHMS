#include "./mclass.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma ONCE
#define _COLS 3
// will be used for Straussen's implementation
class parser {
public:
  // HELPERS
  char *find(string str, char a, int start) {
    char *t = &str[start];
    while (*t != '\0') {
      if (*t == a) {
        return t;
      }
      t++;
    }
    return nullptr;
  }
  void donothing() { return; }
  void intparse(string v, matrixrow *row, char *&k) {
    // CODE IS WRONG CURRENTLY, NEEDS FIXING
    char *i = &v[0];
    unsigned p = 1;
    while (*i != '}') {
      // converts to decimal representation of character ASCII
      (*i <= '9' && *i >= '0') ? row->setelement(p, *i - '0') : donothing();
      i++;
      p++;
    }
    k = i;
  }

  // END HELPERS
  //  - -- - --- -- - - - - - - -- - -------------------->               FOR
  //  CECS            < ------ - - - - - - - - - -- - - - - -- - - -
  vector<matrixrow *> *filein(string in) {
    // start AFTER first bracket
    ifstream f;
    f.open(in);
    string line;
    matrixrow *m;
    vector<matrixrow *> *ans = new vector<matrixrow *>();
    if (!f.fail()) {
      while (getline(f, line, '\n')) {
        char *i = &line[0];
        while (i != &line[line.size() - 1]) {
          // 9 is first number
          // MAIN PROGRAM
          switch (*i) {
          case '{': {
            m = new matrixrow(line.size() / _COLS);
            intparse(line, m, i);
            goto c4;
            break;
          }
          case '#': {
            return ans;
          }
          c4:
          case '}': {
            ans->push_back(m);
            break;
          }
          }
          i++;
        }
        cout << "ERROR " << endl;
        return new vector<matrixrow *>();
      }
      // needs to be changed to
    } else {
      cout << "ERROR reading from file. Please check your spelling and "
              "placement of filename within this directory."
           << endl;
      return new vector<matrixrow *>();
      ;
    }
  }
};
