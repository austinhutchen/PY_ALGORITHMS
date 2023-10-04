#include "./parser.hpp"
#include <cstddef>
#include <iterator>
#include <tgmath.h> //for the type generate macros.
void donothing(void) { return; }
#include <stdio.h>
#define BUFFER_SIZE 1234
// output matrix to python using fwrite
void writeo(vector<matrixrow *> *A, vector<matrixrow *> *B) {
  vector<matrixrow *>::iterator a = A->begin();
  vector<matrixrow *>::iterator b = B->begin();
  while (a != A->end()) {
    (*a)->print();
    a++;
  }
  while (b != B->end()) {
    (*b)->print();
    b++;
  }
  unsigned char local_buf[BUFFER_SIZE];
  /* read from sensor to buffer */
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
#pragma OMP parallel for
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

  A->clear();
  B->clear();
  delete p;
  p = nullptr;
  A = B = nullptr;
}

/*


// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, size N) {

        // Base case
        if (N == 1) {
                return sq_matrix_multiply(A, B, N);
        }

        // Create a new matrix to hold the result
        Matrix C = createMatrix(N);

        size K = N / 2;

        // New sub-matrices
        Matrix A11 = createMatrix(K);
        Matrix A12 = createMatrix(K);
        Matrix A21 = createMatrix(K);
        Matrix A22 = createMatrix(K);
        Matrix B11 = createMatrix(K);
        Matrix B12 = createMatrix(K);
        Matrix B21 = createMatrix(K);
        Matrix B22 = createMatrix(K);


        // Populate the values accordingly
        for (unsigned int i = 0; i < K; i++) {
                for (unsigned j = 0; j < K; j++) {
                        A11[i][j] = A[i][j];
                        A12[i][j] = A[i][K + j];		// Bug solved: I
had a type: A22 instead of A12 A21[i][j] = A[K + i][j]; A22[i][j] = A[K + i][K +
j]; B11[i][j] = B[i][j]; B12[i][j] = B[i][K + j];		// Bug solved: I
had a type: B22 instead of B12 B21[i][j] = B[K + i][j]; B22[i][j] = B[K + i][K +
j];
                }
        }

        // S
        Matrix S1 = subtract(B12, B22, K);
        Matrix S2 = add(A11, A12, K);
        Matrix S3 = add(A21, A22, K);
        Matrix S4 = subtract(B21, B11, K);
        Matrix S5 = add(A11, A22, K);
        Matrix S6 = add(B11, B22, K);
        Matrix S7 = subtract(A12, A22, K);
        Matrix S8 = add(B21, B22, K);
        Matrix S9 = subtract(A11, A21, K);
        Matrix S10 = add(B11, B12, K);

        // P
        Matrix P1 = strassen(A11, S1, K);
        Matrix P2 = strassen(S2, B22, K);
        Matrix P3 = strassen(S3, B11, K);
        Matrix P4 = strassen(A22, S4, K);
        Matrix P5 = strassen(S5, S6, K);
        Matrix P6 = strassen(S7, S8, K);
        Matrix P7 = strassen(S9, S10, K);

        // C_i
        Matrix C11 = subtract(add(add(P5, P4, K), P6, K), P2, K);
// P5 + P4 - P2 + P6
        Matrix C12 = add(P1, P2, K);
// P1 + P2 Matrix C21 = add(P3, P4, K);
// P3 + P4 Matrix C22 = subtract(subtract(add(P5, P1, K), P3, K), P7, K);
// P1 + P5 - P3 - P7

                                                                                                                                                                // C
        for (unsigned int i = 0; i < K; i++) {
                for (unsigned int j = 0; j < K; j++) {

                        C[i][j] = C11[i][j];

                        C[i][j + K] = C12[i][j];

                        C[K + i][j] = C21[i][j];

                        C[K + i][K + j] = C22[i][j];
                }
        }

        // Return the result
        return C;
}


*/