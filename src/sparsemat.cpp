#include <iostream>
#include "sparsemat.hpp"

using namespace std;

namespace SpMV
{

//Define the operation for the Constructor
template <class fp_type>
SparseMatrix<fp_type>::SparseMatrix(const size_t nrows, const size_t ncols)
{
  cout << "Called SparseMatrix<fp_type> constructor" << endl;
  _nrows = nrows;
  _ncols = ncols;

}


//Define the operation for the Destructor
template <class fp_type>
SparseMatrix<fp_type>::~SparseMatrix()
{
  cout << "Called SparseMatrix<fp_type> destructor" << endl;

}


//Define routine to build up coefficients
template <class fp_type>
void SparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
{
  cout << "Called SparseMatrix<fp_type>::setCoefficients" << endl;


}



template class SparseMatrix<float>;
template class SparseMatrix<double>;

}
