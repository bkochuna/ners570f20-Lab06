#include "ellsparsemat.hpp"
#include <iostream>

using namespace std;

template <class fp_type>
ellSparseMat::ellSparseMat(const size_t nrwos, const size_t ncols) : SpMV::_nrows(nrows), SpMV::_ncols(ncols), SpMV::_state(initialized) {
  cout << "called Ellpack constructor" << endl;
}

 
void ellSparseMat::assembleStorage(){

  cout << "hello from Ellpack assembleStorage()" << endl;
}

void ellSparseMat::vec_ptr matVec(const vec_ptr x) {
  cout << "called ellpack matVec"
}

void ellSparseMat::vec_ptr matVec(const fp_type* x) {
  cout << "called ellpack matVec overload"
}


