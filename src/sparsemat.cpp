#include <exception>
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
    this->_nrows = nrows;
    this->_ncols = ncols;

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

  if(this->_state == undefined)
      throw runtime_error("Cannot set coefficients on undefined state!");

  if( this->_state == assembled )
      this->_unAssemble();

  this->_state = building;

  this->_buildCoeff[ make_pair(row,col) ] = aij;
}



template class SparseMatrix<float>;
template class SparseMatrix<double>;

}
