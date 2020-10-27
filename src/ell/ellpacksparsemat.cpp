#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const vector<fp_type> elementVector, const vector<size_t> colIndex)
{
  cout << "Called EllpackSparseMatrix<fp_type> constructor" << endl;

  _ellpackMatrix = EllpackSparseMatrix;

};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
  cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
