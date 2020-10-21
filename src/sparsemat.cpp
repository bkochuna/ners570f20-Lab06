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

// https://www.techiedelight.com/convert-array-vector-cpp/
template <class fp_type>
typename SparseMatrix<fp_type>::vec_ptr SparseMatrix<fp_type>::matVec(const fp_type* x)
{
    // Check that pointer is not null
    if (!x) { throw std::runtime_error("Error: matVec passed nullptr"); }
    // Get length of array from array size over element size
    int n = sizeof(x)/sizeof(x[0]);
    // Construct vector with ranged based constructor
    std::vector<fp_type> vec(x, x+n);
    // Construct vec_ptr from vector
    vec_ptr shared_vec = std::make_shared<vector<fp_type>>(vec);
    // Call interface function
    return matVec(shared_vec);
}



template class SparseMatrix<float>;
template class SparseMatrix<double>;

}
