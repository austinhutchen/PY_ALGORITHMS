#include "./mclass.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <stack>
#include <stdexcept>
#include <string>
#include <system_error>
#include <vector>
using namespace std;
#pragma ONCE
// will be used for Order Statistic implementation

class coordinate {
public:
  // x is a vector in R^2
  coordinate(size_t len) {
    x = new long double[len]();
    this->size = len;
  }
  void setcoord(vector<int> nums) {
    for (int i = 0; i < this->size; i++) {
      x[i] = nums[i];
    }
  }
  long double xn(int n) { return x[n - 1]; }

  void printcoords(int n) {
    for (int i = 0; i < n; i++) {
      cout << "( " << x[i] << " )" << endl;
    }
  }

private:
  long double *x;
  long unsigned size;
};

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

  // adjust for sorting by coordinates

  long double numparse(string line, char *&i) {
    string ans = string();
    char *p = i;
    // run away from non numeric characters
    while (!(*p <= '9' && *p >= '0' || *p == '.')) {
      p++;
    }
    // start adding into double
    while ((*p <= '9' && *p >= '0') || *p == '.') {
      ans += *p;
      p++;
    }
    // i is now at next number index

    if (ans == "1" || ans == "0") {
      i = p;
      return -1;
    }
    try {
      i = p;
      return stold(ans);
    } catch (errc) {
      cout << "error converting" << endl;
      exit(0);
    }
  }
  // END HELPERS
  //  - -- - --- -- - - - - - - -- - -------------------->               FOR
  //  CECS            < ------ - - - - - - - - - -- - - - - -- - - -
  vector<matrixrow *> *filein(string in, ifstream *p) {
    // start AFTER first bracket
    ifstream f;
    f.open(in);
    // vector of rows of arrays of max size 20 representing coordinates
    string line;
      int numind=1;
    // array of "window" of coordinate pointers being compared at a time
    // max of 10 pairs of points per line.
    if (!f.fail()) {
      // allocate on the heap, dealing with large collections of numbers
      while (getline(f, line, '}')) {
        if (!line.empty()) {
          // 9 is first number
          char *i = &line[0];
          // MAIN PROGRAM
          while (i < &line[line.size() - 1]) {
            switch (*i) {
            case '{': {
              // change code to use i while newline character isnt reached to
              // recursively call numparse on sets of coordinates
              i++;
              matrixrow *m = new matrixrow(line.size());
              m->setelement(numind, numparse(line, *&i));
              numind++;
              break;
            }

            default: {
              break;
            }
              // will insert newline char at end of string
              // double answer = atof(buffer);
              //  temp.push_back(buffer)
              // each point in array represents a pair of coordinates
            }
            i++;
            // nums.push_back(points);
            // float parse
          }
        }
      }
      // p will now point to end of f
      p = &f;
      return points;
    } else {
      cout << "ERROR reading from file. Please check your spelling and "
              "placement of filename within this directory."
           << endl;
      return new vector<matrixrow *>();
      ;
    }
  }
};
