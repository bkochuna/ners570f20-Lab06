#include <exception>
#include <iostream>
#include "../sparsemat.hpp"
#include "csrsparsemat.hpp"


namespace SpMV {

// Csr SparseMatrix Constructor
template <class fp_type>
CsrSparseMatrix<fp_type>::CsrSparseMatrix(const size_t nrows, const size_t ncols) :
    SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{
    cout << "Called CsrSparseMatrix<fp_type> constructor" << endl;
    this->_state = initialized;
}

// Csr SparseMatrix Destructor
template <typename fp_type>
CsrSparseMatrix<fp_type>::~CsrSparseMatrix(){
    cout << "Called CsrSparseMatrix<fp_type> destructor" << endl;
}


// Csr Assemble Storage
template <typename fp_type>
void CsrSparseMatrix<fp_type>::assembleStorage(){

    cout << "Called CsrSparseMatrix<fp_type>::assembleStorage" << endl;

    if( this->_state == undefined ) {
        throw runtime_error("Cannot set coefficients on undefined state!"
                            "Developer error, state should not be encountered.");
    }
    else if ( this->_state == initialized ) {
        throw runtime_error("Cannot set coefficients on initialized state!"
                            "First use setCoefficient() routine.");
    }
    else if ( this->_state == assembled ) {
        throw runtime_error("Cannot set coefficients on assembled state!"
                            "First use setCoefficient() routine.");
    }
    else { // State is building
        for ( auto coeff : this->_buildCoeff ) {
            row_idx.push_back(coeff.first.first);
            col_idx.push_back(coeff.first.second);
            csr_matrix.push_back(coeff.second);
        }

        this->_state = assembled;
    }
    return;
}



// Csr unAssemble Storage
template<typename fp_type>
void CsrSparseMatrix<fp_type>::_unAssemble(){
    if( this->_state == undefined ) {
        throw runtime_error("Cannot unset coefficients on undefined state!"
                    "Developer error, state should not be encountered.");
    }
    else if ( this->_state == initialized ) {
        throw runtime_error("Cannot unset coefficients on initialized state!"
                    "Developer error, call unAssemble on assembled state");
    }
    else if ( this->_state == building ) {
        throw runtime_error("Cannot unset coefficients on building state!"
                    "Developer error, call unAssemble on assembled state");
    }
    else { // State is assembled

        // Clear row, col and matrix vectors
        row_idx.clear();
        col_idx.clear();
        csr_matrix.clear();

        if ( this->_buildCoeff.empty() ) {
            this->_state = initialized;
        }
        else {
            this->_state = building;
        }
    }
    return;
}



// Csr Mat Vec
template<typename fp_type>
typename CsrSparseMatrix<fp_type>::vec_ptr
CsrSparseMatrix<fp_type>::matVec(const vec_ptr x) {

    if ( this->_state != assembled ) {
        throw runtime_error("Error: matVec can only be called on an assembled "
                            "matrix");
    }

    unsigned int size = csr_matrix.size();
    int i,j;

    vector<fp_type> y(size, 0);

    for (unsigned int n=0; n<size; n++){
       
        for (int m=row_idx(n); m<(row_idx(n+1)-1);m++){

             y.at(n) = y.at(n) + csr_matrix.at(m)*x->at(col_idx(m));
    };

    return make_shared<vector<fp_type>>(y);
}



template class CsrSparseMatrix<float>;
template class CsrSparseMatrix<double>;

} // end SpMV naemspace