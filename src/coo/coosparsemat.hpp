#ifndef _COO_SPARSE_MATRIX_HEADER_
#define _COO_SPARSE_MATRIX_HEADER_

#include "../sparsemat.hpp"

#include <iostream>

using namespace std;

namespace SpMV {


//Concrete implementation of the SparseMatrix abstract class using coordinate
//list formatting for the stored sparse matrix
template<typename fp_type>
class CooSparseMatrix : public SparseMatrix<fp_type> {
    private:
        vector<fp_type> coo_matrix;
        vector<int> row_idx col_idx;
    public:
        // Define an alias for the gross type that templating produces
        typedef typename SparseMatrix<fp_type>::vec_ptr vec_ptr;

        //Constructor - receives two inputs: number of rows and numer of
        //columns, constructs parent class
        CooSparseMatrix(const size_t nrows, const size_t ncols) :
                        SparseMatrix<fp_type>(nrows, ncols) {};
        
        //Deconstructor - no dynamic memory to manage, no need to implement
        //anything
        ~CooSparseMatrix() {};

        //Constructor - receives three inputs: element, col idx, row idx vectors
        //Builds COO sparce matrix based on the input information
        //NOTE: this constructor is not required for overall design
        // CooSparseMatrix(const vector<fp_type> & element_vec,
        //                 const vector<int> & col_vec,
        //                 const vector<int> & row_vec);


    
        //Print the coo_matrix
        // void printMatrix();

        //Implementation of assembling matrix storage in COO format
        //from _buildCoeff member variable of parent class
        void assembleStorage() override;


        //Implementation of unassembling matrix storage in COO format
        //from _buildCoeff member variable of parent class
        void _unAssemble() override;

        //Implementation of matrix vector muliplication
        vec_ptr  matVec(const vec_ptr x) override;

};

} // end SpMV naemspace

#endif