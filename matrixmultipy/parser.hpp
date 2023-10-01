#include "./mclass.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma ONCE
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
  void intparse(string v, matrixrow *row) {
    // CODE IS WRONG CURRENTLY, NEEDS FIXING
    char *i = &v[0];
    unsigned p = 1;
    while (*i != '\0') {
      // converts to decimal representation of character ASCII
      (*i <= '9' && *i >= '0') ? row->setelement(p, *i - '0') : donothing();
      i++;
      p++;
    }
  }
  // adjust for sorting by coordinates
  void numparse(string line, char *&i, matrixrow *row) {
    // does not currently grab double digit numbers, needs fixing
    string ans;
    while (*i != '#') {
      ans = string();
      while (*i != '}') {
        (*i <= '9' && *i >= '0') ? ans += *i : i++;
      }
      if (ans.size() != 0) {
        intparse(ans, row);
      }
      i++;
    }
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
        if (!line.empty()) {
          // 9 is first number
          char *i = &line[0];
          // MAIN PROGRAM
          switch (*i) {
          case '{': {
            m = new matrixrow(line.size() - 2);
            intparse(line, m);
            break;
          }
          case '#': {
            return ans;
          }
          }
          i++;
          ans->push_back(m);
        } else {
          cout << "ERROR " << endl;
          return new vector<matrixrow *>();
        }
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
