#include "./parser.hpp"
#include <complex.h> //complex variables and complex unit I
#include <tgmath.h>  //for the type generate macros.
void donothing(void) { return; }
void matrixmult(vector<matrixrow *> A, vector<matrixrow *> B) {
  // A and B are now both square

  return;
}

void padmatrix(vector<matrixrow *> *A, vector<matrixrow *> *B) {
  bool Agood = (A->size() % 2 != 0);
  if (Agood) {
    cout << "A NOT PADDED" << endl;
  } else {
    cout << "B NOT PADDED" << endl;
  }
  switch (Agood) {
  case 0: {
    // B is culprit;

  }

  case 1: {
    // A is culprit for pad with zeroes

  }
  }
}

int main(int argc, char **argv) {
  parser *p = new parser();
  if (argv[1] && argv[2]) {
    // As noted on wp, you could pad with zeroes, and strip them on exit,
    // instead of crashing for non-square 2n matrices.
    vector<matrixrow *> *A = p->filein(argv[1]);
    vector<matrixrow *> *B = p->filein(argv[2]);
    bool safe = (A->size() % 2 == 0 && B->size() % 2 == 0);
    safe ? matrixmult(*A, *B) : padmatrix(A, B);

    A->clear();
    B->clear();
    A = B = 0x0;
  }
}
