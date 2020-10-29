#include <exception>
#include <iostream>
#include "../sparsemat.hpp"
#include "coosparsemat.hpp"


namespace SpMV {

// COO SparseMatrix Constructor
template <class fp_type>
CooSparseMatrix<fp_type>::CooSparseMatrix(const size_t nrows, const size_t ncols) :
    SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{
    cout << "Called CooSparseMatrix<fp_type> constructor" << endl;
    this->state = initialized;
};

// COO SparseMatrix Destructor
template <typename fp_type>
CooSparseMatrix<fp_type>::~CooSparseMatrix(){
    cout << "Called CooSparseMatrix<fp_type> destructor" << endl;
};


// COO Assemble Storage
template <typename fp_type>
void CooSparseMatrix<fp_type>::assembleStorage(){

    cout << "Called COOSparseMatrix<fp_type>::assembleStorage" << endl;

    if(this->_state == undefined)
        throw runtime_error("Cannot set coefficients on undefined state!");
    else if (this->_state == initialized)
        throw runtime_error("Cannot set coefficients on initialized state!");

    if( this->_state == assembled )
        this->_unAssemble();
        return;

    map<make_pair(int,int),fp_type>::iterator i;

    for ( i = _buildCoeff.begin(); i != _buildCoeff.end(); i++ ){
        this->row_idx.push_back(i->first.first);
        this->col_idx.push_back(i->first.second);
        this->coo_matrix.push_back(i->second);
    };

    _buildCoeff.clear();

    this->_state = assembled;
    return;
};



// COO unAssemble Storage
template<typename fp_type>
void CooSparseMatrix<fp_type>::_unAssemble(){
    if(this->_state == undefined)
        throw runtime_error("Cannot unset coefficients on undefined state!");
    else if (this->_state == initialized)
        throw runtime_error("Cannot unset coefficients on initialized state!");
    else if (this->_state == building)
        throw runtime_error("Cannot unset coefficients on building state!");

    // Clear row, col and matrix vectors
    this->row_idx.clear()
    this->col_idx.clear()
    this->coo_matrix.clear()

    this->_state = initialized;

    return;
};



// COO Mat Vec
template<typename fp_type>
vec_ptr CooSparseMatrix<fp_type>::matVec(const vec_ptr x){

    unsigned int size = this->coo_matrix.size();
    unsigned int n;
    int i,j;

    vec_ptr<fp_type> new y(size);
    for (n=0;n<size;n++){
        *y[n] = 0;
    };

    for (n=0;n<size;n++){
        i=this->row_idx[n];
        j=this->col_idx[n];
        *y[i] = *y[i] + this->coo_matrix[n]*(*x[j]);
    };

    return y;
};



template class CooSparseMatrix<float>;
template class CooSparseMatrix<double>;

} // end SpMV naemspace

