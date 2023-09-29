#include "./parser.hpp"
#include <complex.h> //complex variables and complex unit I
#include <tgmath.h>  //for the type generate macros.

int main(int argc, char **argv) {
  char *line;
  parser *p = new parser();
  ifstream *file;
  if (argv[1] != nullptr) {
    // filein will need to be ran twice with diff start ptr
    p->filein(argv[1], file);
  }
}