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
        typedef typename SpMV::SparseMatrix<fp_type>::vec_ptr vec_ptr;

        //Constructor - constructs the child as an instance of the parent class
        cscSparseMatrix(const size_t nrows, const size_t ncols) :
            SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows,ncols)
            { cout << "cscSpMat::constructor" << endl;}

        // Assembles the matrix: Will store the info in _buildCoeff
        // attribute of the parent class into the child (CSC) class'
        // attributes elemA, colPointer and rowIdx (or as decided by the
        // implementation team)
        void assembleStorage()
        { cout << "cscSpMat::assembleStorage" << endl; }

        // Performs matrix-vector multiplication
        vec_ptr matVec(const vec_ptr x) override
        { cout << "cscSpMat::matVec" << endl; return NULL; }

        // Csc sparse matrix destructor
        ~cscSparseMatrix()
        { cout << "cscSpMat::destructor" << endl;}
};
