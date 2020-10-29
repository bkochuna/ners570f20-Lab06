#ifndef _COO_SPARSE_MATRIX_HEADER_
#define _COO_SPARSE_MATRIX_HEADER_

#include "../sparsemat.hpp"

#include <iostream>

using namespace std;

//namespace SpMV {


// Concrete implementation of the SparseMatrix abstract class using coordinate
// list formatting for the stored sparse matrix.
// Constructed template types: float, double
template<typename fp_type>
class CooSparseMatrix : public SpMV::SparseMatrix<fp_type> {
    private:
        // Vector of elements of sparse matrix. Element at index i of
        // coo_matrix belongs in matrix position with row number given by index
        // i of row_idx and column number given by index i of col_idx
        // Note: Matrix is 0-based indexed
        vector<fp_type> coo_matrix;
        vector<int> row_idx, col_idx;

        // Accepted states: assembled
        // Effect: Clears all private member variables
        // Assumptions: None
        // Outgoing state: initialized if _buildCoeff is empty,
        // building otherwise
        void _unAssemble() override;
        
    public:
        // Define an alias for the gross type that templating produces
        typedef typename SpMV::SparseMatrix<fp_type>::vec_ptr vec_ptr;

        // Constructor
        // Effect: Initalizes class and prints message
        // Assumptions: nrows and ncols are non-zero positive integers
        // Outgoing state: initialized
        CooSparseMatrix(const size_t nrows, const size_t ncols);
        
        // Deconstructor
        // Effect: Destroys class and prints message
        // Assumptions: None
        // Outgoing state: None
        ~CooSparseMatrix();

        // Accepted states: building
        // Effect: Populates member variables using _buildCoeff values
        // Assumptions: _buildCoeff contains valid element values and
        // coordinates
        // Outgoing state: assembled
        void assembleStorage() override;

        // Accepted states: assembled
        // Effect: Performs matrix vector muliplication of stored matrix and
        // argument x and returns the vector result
        // Assumptions: Dimensions of vector x are consistent with stored
        // matrix
        // Outgoing state: assembled
        vec_ptr  matVec(const vec_ptr x) override;

};

//} // end SpMV naemspace

#endif
