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

  void save_integer(char *&i, matrixrow *&row) {
    string ans = string();
    unsigned char next = *(i + 1);
    unsigned char prev = *(i - 1);
    int val;

    // sign integers if they're negative, and properly store double digits
    if (next <= 57 && next >= 48) {
      ans += (*i);
      ans += next;
    }
    if (ans.size() == 0) {
      ans = *i;
      if (prev == '-') {
        // two's comp for negative integers
        val = (~(*i - '0') + 1);
        row->setelement(val);
        i++;
        return;
      } else {
        // positive ints can just be converted
        row->setelement(stoi(ans));
        i++;
      }
    } else {
      // double digit or unknown char
      try {
        val = stoi(ans);
        if (prev == '-') {
          // two's comp for negative integers
          val = (~val + 1);
          row->setelement(val);
          i++;
          return;
        } else {
          row->setelement(val);
          i++;
          return;
        }
      } catch (exception &err) {
        cout << "INTEGER CONVERSION ERROR" << endl;
        return;
      }
    }

  }

  void donothing(void) { return; }

  void intparse(matrixrow *row, char *k) {
    char *p = k;
    while (*p != '#') {
      // converts to decimal representation of character ASCII between 0 and 9,
      // adding to row in free index
      (*p <= 57 && *p >= 48 && row->safe()) ? save_integer(p, row)
                                            : donothing();
      p++;
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
            intparse(row, i);
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
