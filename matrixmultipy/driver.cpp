#include "./parser.hpp"
#include <complex.h> //complex variables and complex unit I
#include <cstddef>
#include <iterator>
#include <tgmath.h> //for the type generate macros.
void donothing(void) { return; }

int _strassens() {}
int matrixmult(vector<matrixrow *> A, vector<matrixrow *> B) {
  // A and B are now both square, padded with zeroes
  // work with strassen's
  vector<matrixrow *>::iterator A_itr_1 = A.begin();
  vector<matrixrow *>::iterator B_itr_1 = B.begin();
  vector<matrixrow *>::const_iterator middleA = A.begin() + (A.size() / 2);
  vector<matrixrow *>::const_iterator middleB = B.begin() + (B.size() / 2);
  vector<matrixrow *>::iterator A_itr_2 = A.begin() + (A.size() / 2);
  vector<matrixrow *>::iterator B_itr_2 = B.begin() + (B.size() / 2);
  vector<matrixrow *> A_L(A.size() / 2);
  vector<matrixrow *> A_R(A.size() / 2);
  vector<matrixrow *> B_L(B.size() / 2);
  vector<matrixrow *> B_R(B.size() / 2);
  unsigned counter = 0;
  while (A_itr_1 != middleA && A_itr_2 != A.end()) {
    A_L[counter] = *A_itr_1;
    A_R[counter] = *A_itr_2;
    A_itr_1++;
    A_itr_2++;
    counter++;
  }
  counter = 0;
  while (B_itr_1 != middleB && B_itr_2 != B.end()) {
    B_L[counter] = *B_itr_1;
    B_R[counter] = *B_itr_2;
    B_itr_1++;
    B_itr_2++;
    counter++;
  }
  // split is made, perform recursion and multiplication below
  int result;
  auto vec = B_L.begin();
  auto vec2 = B_R.begin();
  auto vec3 = A_L.begin();
  auto vec4 = A_R.begin();
  while (vec != B_L.end()) {
    for (int i = 1; i <= (*vec)->size(); i++) {
      result += (*vec)->entrylookup(1) * (*vec3)->entrylookup(i);
    }
    for (int i = 1; i <= (*vec2)->size(); i++) {
      result += (*vec2)->entrylookup(1) * (*vec4)->entrylookup(i);
    }

    vec++;
    vec2++;
    vec3++;
    vec4++;
  }

  return result;
}

bool isPowerOfTwo(int n) {
  if (n == 0)
    return false;

  return (ceil(log2(n)) == floor(log2(n)));
}

void pad(vector<matrixrow *> *&nums) {
  // pad with zeroes until size is power of two

  nums->push_back(new matrixrow(nums[0].size() + 1, 0));
}

void padmatrix(vector<matrixrow *> *&A, vector<matrixrow *> *&B) {
  (isPowerOfTwo(A->size())) ? donothing() : pad(A);
  (isPowerOfTwo(B->size())) ? donothing() : pad(B);
}

int main(int argc, char **argv) {
  parser *p = new parser();
  // As noted on wp, you could pad with zeroes, and strip them on exit,
  // instead of crashing for non-square 2n matrices.
  vector<matrixrow *> *A = p->filein("a.txt");
  vector<matrixrow *> *B = p->filein("b.txt");
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
  cout << " A * B = " << matrixmult(*A, *B) << endl;
  A->clear();
  B->clear();
  delete p;
  p = nullptr;
  A = B = nullptr;
}
