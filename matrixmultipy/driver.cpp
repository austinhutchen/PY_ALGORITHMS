#include "./parser.hpp"
#include <complex.h> //complex variables and complex unit I
#include <tgmath.h>  //for the type generate macros.


int matrixmult(vector<matrixrow *> A, vector<matrixrow *> B){
// strassen's algorithm will go here




return 3;
}
int main(int argc, char **argv) {
  char *line;
  parser *p = new parser();
  ifstream *file;
  if (argv[1] && argv[2]) {
   vector<matrixrow *>* A= p->filein(argv[1], file);
      vector<matrixrow *>* B= p->filein(argv[2], file);
  cout << "ANSWER: " << matrixmult(*A,*B) <<endl;
  delete A;
  delete B;
  A= B =0x0;

  }
}