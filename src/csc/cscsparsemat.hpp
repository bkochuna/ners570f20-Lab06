#include <vector>
#include <iostream>
#include "sparsemat.hpp"

using namespace std;

template<class fp_type>
class cscSparseMatrix : public SpMV::SparseMatrix<fp_type>
{
    private:
        void _unAssemble()
        { cout << "cscSpMat::unAssemble" << endl; }
    public:
        typedef typename SpMv::SparseMatrix<fp_type>::vec_ptr vec_ptr;

        //Constructor - receives three inputs: element, col pointer, row idx vectors
        //Builds CSC sparce matrix based on the input information
        cscSparseMatrix(const size_t nrows, const size_t ncols) :
            spMV::SparseMatrix<fp_type>::SparseMatrix(nrows,ncols)
            { cout << "csrSpMat::constructor" << endl;}

        // Assembles the matrix
        void assembleStorage()
        { cout << "cscSpMat::matVec" << endl; return NULL; }

        // Performs matrix-vector multiplication
        vec_ptr matVec(const vec_ptr x) override
        { cout << "csrSpMat::matVec" << endl; return NULL; }

        // Csc sparse matrix destructor
        ~cscSparseMatrix()
        { cout << "cscSpMat::destructor" << endl;}

        //Print the csc_matrix
        void printMatrix();

};
