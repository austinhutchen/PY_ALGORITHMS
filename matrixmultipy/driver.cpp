#include "./parser.hpp"
#include <complex.h> //complex variables and complex unit I
#include <tgmath.h>  //for the type generate macros.
void donothing(void) { return; }
void matrixmult(vector<matrixrow *> A, vector<matrixrow *> B) {
  // A and B are now both square, padded with zeroes
  vector<matrixrow *>::iterator A_itr_1 = A.begin();
  vector<matrixrow *>::iterator B_itr_1 = B.begin();
  __wrap_iter<matrixrow **> middle = A.begin() + (A.size() / 2);
  vector<matrixrow *>::iterator A_itr_2 = A.begin() + (A.size() / 2);
  vector<matrixrow *>::iterator B_itr_2 = B.begin() + (B.size() / 2);
  vector<matrixrow *> A_L(A.size() / 2);
  vector<matrixrow *> A_R(A.size() / 2);
  vector<matrixrow *> B_L(A.size() / 2);
  vector<matrixrow *> B_R(A.size() / 2);
  unsigned counter = 0;
  while (A_itr_1 != middle && A_itr_2 != A.end()) {
    A_L[counter] = *A_itr_1;
    A_R[counter] = *A_itr_2;
    A_itr_1++;
    A_itr_2++;
  }
  while (B_itr_1 != middle && B_itr_2 != B.end()) {
    B_L[counter] = *B_itr_1;
    B_R[counter] = *B_itr_2;
    B_itr_1++;
    B_itr_2++;
  }
  // split is made

  int result = 32;
  cout << "Matrix multiplication result is : " << result << endl;
  return;
}
bool isPowerOfTwo(int n) {
  if (n == 0)
    return false;

  return (ceil(log2(n)) == floor(log2(n)));
}

void pad(vector<matrixrow *> *&nums) {
  // pad with zeroes until size is power of two
  nums->push_back(new matrixrow(nums[0].size(), 0));
}

void padmatrix(vector<matrixrow *> *&A, vector<matrixrow *> *&B) {
  (isPowerOfTwo(A->size())) ? donothing() : pad(A);
  (isPowerOfTwo(B->size())) ? donothing() : pad(B);
}

int main(int argc, char **argv) {
  parser *p = new parser();
  if (argv[1] && argv[2]) {
    // As noted on wp, you could pad with zeroes, and strip them on exit,
    // instead of crashing for non-square 2n matrices.
    vector<matrixrow *> *A = p->filein(argv[1]);
    vector<matrixrow *> *B = p->filein(argv[2]);
    vector<matrixrow *>::iterator a = A->begin();
    vector<matrixrow *>::iterator b = B->begin();
    bool safe = (isPowerOfTwo(A->size()) && isPowerOfTwo(B->size()));
    safe ? donothing() : padmatrix(A, B);
    cout << "A DIMENSION: " << A->size() << " "
         << "B DIMENSION: " << B->size() << endl;
    cout << "MATRIX A:" << endl;
    while (a != A->end()) {
      (*a)->print();
      a++;
    }
    cout << "MATRIX B:" << endl;
    while (b != B->end()) {
      (*b)->print();
      b++;
    }
    matrixmult(*A, *B);
    A->clear();
    B->clear();
    A = B = 0x0;
  }
}
