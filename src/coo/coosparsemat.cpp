#include <exception>
#include <iostream>

#include "coosparsemat.hpp"


//namespace SpMV {

// COO SparseMatrix Constructor
template <class fp_type>
CooSparseMatrix<fp_type>::CooSparseMatrix(const size_t nrows, const size_t ncols) :
    SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{
    cout << "Called CooSparseMatrix<fp_type> constructor" << endl;
    this->_state = SpMV::initialized;
}

// COO SparseMatrix Destructor
template <typename fp_type>
CooSparseMatrix<fp_type>::~CooSparseMatrix(){
    cout << "Called CooSparseMatrix<fp_type> destructor" << endl;
}


// COO Assemble Storage
template <typename fp_type>
void CooSparseMatrix<fp_type>::assembleStorage(){

    cout << "Called COOSparseMatrix<fp_type>::assembleStorage" << endl;

    if( this->_state == SpMV::undefined ) {
        throw runtime_error("Cannot set coefficients on undefined state!"
                            "Developer error, state should not be encountered.");
    }
    else if ( this->_state == SpMV::initialized ) {
        throw runtime_error("Cannot set coefficients on initialized state!"
                            "First use setCoefficient() routine.");
    }
    else if ( this->_state == SpMV::assembled ) {
        throw runtime_error("Cannot set coefficients on assembled state!"
                            "First use setCoefficient() routine.");
    }
    else { // State is building
        for ( auto coeff : this->_buildCoeff ) {
            row_idx.push_back(coeff.first.first);
            col_idx.push_back(coeff.first.second);
            coo_matrix.push_back(coeff.second);
        }

        this->_state = SpMV::assembled;
    }
    return;
}



// COO unAssemble Storage
template<typename fp_type>
void CooSparseMatrix<fp_type>::_unAssemble(){
    if( this->_state == SpMV::undefined ) {
        throw runtime_error("Cannot unset coefficients on undefined state!"
                    "Developer error, state should not be encountered.");
    }
    else if ( this->_state == SpMV::initialized ) {
        throw runtime_error("Cannot unset coefficients on initialized state!"
                    "Developer error, call unAssemble on assembled state");
    }
    else if ( this->_state == SpMV::building ) {
        throw runtime_error("Cannot unset coefficients on building state!"
                    "Developer error, call unAssemble on assembled state");
    }
    else { // State is assembled

        // Clear row, col and matrix vectors
        row_idx.clear();
        col_idx.clear();
        coo_matrix.clear();

        if ( this->_buildCoeff.empty() ) {
            this->_state = SpMV::initialized;
        }
        else {
            this->_state = SpMV::building;
        }
    }
    return;
}



// COO Mat Vec
template<typename fp_type>
typename CooSparseMatrix<fp_type>::vec_ptr
CooSparseMatrix<fp_type>::matVec(const vec_ptr x) {

    if ( this->_state != SpMV::assembled ) {
        throw runtime_error("Error: matVec can only be called on an assembled "
                            "matrix");
    }

    unsigned int size = coo_matrix.size();
    int i,j;

    vector<fp_type> y(this->_nrows, 0);

    for (unsigned int n=0; n<size; n++){
        i=row_idx.at(n);
        j=col_idx.at(n);
        y.at(i) = y.at(i) + coo_matrix.at(n)*x->at(j);
    };

    return make_shared<vector<fp_type>>(y);
}



template class CooSparseMatrix<float>;
template class CooSparseMatrix<double>;

//} // end SpMV naemspace

