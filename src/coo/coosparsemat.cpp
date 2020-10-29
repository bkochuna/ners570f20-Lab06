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

    // Enforced accepted state, throw error otherwise
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
        // Store the row index, column index, and value of each element in
        // _buildCoeff in the respective member variable at the same index
        // in each member variable
        // e.g. ((row,col),val) -> ((row_idx[i], col_idx[i]), coo_matrix[i])
        for ( auto coeff : this->_buildCoeff ) {
            row_idx.push_back(coeff.first.first);
            col_idx.push_back(coeff.first.second);
            coo_matrix.push_back(coeff.second);
        }

        // Set outgoing state
        this->_state = SpMV::assembled;
    }
    return;
}



// COO unAssemble Storage
template<typename fp_type>
void CooSparseMatrix<fp_type>::_unAssemble(){

    // Enforced accepted state, throw error otherwise
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

        // "Undo" assembleMatrix, return state that would have been present
        // if assembleMatrix had not been called
        if ( this->_buildCoeff.empty() ) {
            // Note: this is not a reachable option, included in case the
            // accepted states of assembleMatrix change
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

    // Enforced accepted state, throw error otherwise
    if ( this->_state != SpMV::assembled ) {
        throw runtime_error("Error: matVec can only be called on an assembled "
                            "matrix");
    }

    // Get the number of elements in the sparse matrix
    unsigned int size = coo_matrix.size();
    int i,j;

    // Initialize the return vector the size of the number of rows in the
    // matrix to zeros
    vector<fp_type> y(this->_nrows, 0);

    // For every element in the matrix add the product of the matrix element at
    // (i,j) with the multiplying vector element at j to the resultant vector
    // element at i
    for (unsigned int n=0; n<size; n++){
        i=row_idx.at(n);
        j=col_idx.at(n);
        y.at(i) = y.at(i) + coo_matrix.at(n)*x->at(j);
    };

    // Result vec_ptr to resultant vector
    return make_shared<vector<fp_type>>(y);
}



template class CooSparseMatrix<float>;
template class CooSparseMatrix<double>;

//} // end SpMV naemspace

