#ifndef _COO_SPARSE_MATRIX_HEADER_
#define _COO_SPARSE_MATRIX_HEADER_

#include "../sparsemat.hpp"

#include <iostream>

using namespace std;

//namespace SpMV {


//Concrete implementation of the SparseMatrix abstract class using coordinate
//list formatting for the stored sparse matrix
template<typename fp_type>
class CooSparseMatrix : public SpMV::SparseMatrix<fp_type> {
    private:
        // Vector of elements of sparse matrix. Element at index i of
        // coo_matrix belongs in matrix position with row number given by index
        // i of row_idx and column number given by index i of col_idx
        vector<fp_type> coo_matrix;
        vector<int> row_idx, col_idx;

        //Implementation of unassembling matrix storage in COO format
        //from _buildCoeff member variable of parent class
        void _unAssemble() override;
        
    public:
        // Define an alias for the gross type that templating produces
        typedef typename SpMV::SparseMatrix<fp_type>::vec_ptr vec_ptr;

        //Constructor - receives two inputs: number of rows and numer of
        //columns, constructs parent class
        CooSparseMatrix(const size_t nrows, const size_t ncols);
        
        //Deconstructor - no dynamic memory to manage, no need to implement
        //anything
        ~CooSparseMatrix();

        //Implementation of assembling matrix storage in COO format
        //from _buildCoeff member variable of parent class
        void assembleStorage() override;

        //Implementation of matrix vector muliplication
        vec_ptr  matVec(const vec_ptr x) override;

};

//} // end SpMV naemspace

#endif
