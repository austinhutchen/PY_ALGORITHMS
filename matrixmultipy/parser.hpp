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

  void save_integer(char *i, matrixrow *&row) {
    string ans = string();
    char next = *(++i);
    char prev = *(--i);
    // sign integers if they're negative, and properly store double digits
    if (next <= 57 && next >= 48) {
      ans += (*i);
      ans += next;
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

    if (prev == '-') {
      // two's comp for negative integers
      val = (~val + 1);
    }
    ans.size() == 0 ? row->setelement(*i - '0') : row->setelement(val);
  }

  void donothing() { return; }

  void intparse(string v, matrixrow *row, char *k) {
    char *i = k;
    while (*i != '#') {
      // converts to decimal representation of character ASCII between 0 and 9,
      // adding to row in free index
      (*i <= 57 && *i >= 48 && row->safe()) ? save_integer(i, row)
                                            : donothing();
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
    matrixrow *row;
    vector<matrixrow *> *matrix = new vector<matrixrow *>();
    if (!f.fail()) {
      while (getline(f, line, '\n')) {
        char *i = &line[0];
        while (*i != '#') {
          // 9 is first number
          // MAIN PROGRAM
          switch (*i) {
          case '{': {
            row = new matrixrow((line.size() / _COLS));
            intparse(line, row, i);
            break;
          }
          case '}': {
            if (*(++i) == '}') {
              matrix->push_back(row);
              return matrix;
            } else {
              matrix->push_back(row);
            }
            break;
          }
          }
          i++;
        }
        return matrix;
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
