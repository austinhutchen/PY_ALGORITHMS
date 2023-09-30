#include "./mclass.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma ONCE
// will be used for Order Statistic implementation
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

  void intparse(string v, vector<int> *destination) {
    // CODE IS WRONG CURRENTLY, NEEDS FIXING
    v = v.c_str();
    vector<int>::iterator p = destination->begin();
    char *i = &v[0];
    while (*i != '\0') {
      // converts to decimal representation of character ASCII
      *p = *i - '0';
      i++;
      p++;
    }
  }
  // adjust for sorting by coordinates
  void numparse(string line, char *&i, matrixrow *row) {
    char *p = i;
    // does not currently grab double digit numbers, needs fixing
    while (*p != '#') {
      string ans = string();
      while (*p != '}') {
        (*p <= '9' && *p >= '0') ? ans += *p : p++;
      }
      intparse(ans, row->handoff());
    }
  }

  // END HELPERS
  //  - -- - --- -- - - - - - - -- - -------------------->               FOR
  //  CECS            < ------ - - - - - - - - - -- - - - - -- - - -
  vector<matrixrow *> *filein(string in, ifstream *p) {
    // start AFTER first bracket
    ifstream f;
    f.open(in);
    string line;
    matrixrow *m;
    vector<matrixrow *> *ans = new vector<matrixrow *>();
    if (!f.fail()) {
      while (getline(f, line, '#')) {
        if (!line.empty()) {
          // 9 is first number
          char *i = &line[1];
          // MAIN PROGRAM
          switch (*i) {
          case '{': {
            i++;
            m = new matrixrow(line.size() - 2);
            numparse(line, *&i, m);
            int counter = 0;
            break;
          }
          default: {
            break;
          }
          }
          i++;
          ans->push_back(m);
        }
      }
      p = &f;
      // needs to be changed to
      return ans;
    } else {
      cout << "ERROR reading from file. Please check your spelling and "
              "placement of filename within this directory."
           << endl;
      return new vector<matrixrow *>();
      ;
    }
  }
};
