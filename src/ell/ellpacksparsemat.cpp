#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
ellpackSparseMatrix<fp_type>::ellpackSparseMatrix(const vector<fp_type> elementVector, const vector<size_t> colIndex)
{
  cout << "Called ellpackSparseMatrix<fp_type> constructor" << endl;

  _ellpackMatrix = ellpackSparseMatrix;

}

template <class fp_type>
ellpackSparseMatrix<fp_type>::~ellpackSparseMatrix()
{
  cout << "Called ellpackSparseMatrix<fp_type> destructor" << endl;
}
