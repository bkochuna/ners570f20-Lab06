#include <exception>
#include <iostream>
#include "sparsemat.hpp"

using namespace std;

namespace SpMV
{

//Define the operation for the Constructor
template <class fp_type>
SparseMatrix<fp_type>::SparseMatrix(const size_t nrows, const size_t ncols) :
    _nrows(nrows), _ncols(ncols), _state(initialized)
{
    cout << "Called SparseMatrix<fp_type> constructor" << endl;
}


//Define the operation for the Destructor
template <class fp_type>
SparseMatrix<fp_type>::~SparseMatrix()
{
    cout << "Called SparseMatrix<fp_type> destructor" << endl;
    this->_nrows = 0;
    this->_ncols = 0;
    this->_state = undefined;
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
