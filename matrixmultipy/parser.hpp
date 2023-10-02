#include "./mclass.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma ONCE
#define _COLS 9
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
  void check(char *i, matrixrow *&row) {
    string ans = string();
    char next = *(++i);
    char prev = *(--i);
    // sign integers if they're negative, and properly store double digits
    if (next <= 57 && next >= 48) {
      ans += next;
      ans += (*i);
    }
    int val;
    if (ans.size() > 0) {
      try {
        val = stoi(ans);
      } catch (exception &err) {
        cout << "INTEGER CONVERSION ERROR" << endl;
        return;
      }
    }

    if (prev == ('-')) {
      val = ~val + 1;
    }
    ans.size() == 0 ? row->setelement(*i - '0') : row->setelement(val);
  }

  void donothing() { return; }

  void intparse(string v, matrixrow *row, char *&k) {
    // CODE IS WRONG CURRENTLY, NEEDS FIXING
    char *i = k;
    while (*i != '#') {
      // converts to decimal representation of character ASCII between 0 and 8
      (*i <= 57 && *i >= 48 && row->safe()) ? check(i, row) : donothing();
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
        char *i = &line[0];
        while (*i != '#') {
          // 9 is first number
          // MAIN PROGRAM
          switch (*i) {
          case '{': {
            m = new matrixrow((line.size() / _COLS));
            intparse(line, m, i);
            break;
          }
          case '}': {
            ans->push_back(m);
            break;
          }
          }
          i++;
        }
        return ans;
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
