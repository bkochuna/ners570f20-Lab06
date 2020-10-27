#include <vector>
#include <iostream>
<<<<<<< HEAD

using namespace std;

template<typename T>
class CscSparseMatrix{
    private:
        vector<vector<T>> csc_matrix;
    public:
        //Constructor - receives three inputs: element, col pointer, row idx vectors
        //Builds CSC sparce matrix based on the input information
        CscSparseMatrix(const vector<T> & element_vec, const vector<int> & colp_vec, const vector<int> & row_vec);
=======
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
            { cout << "cscSpMat::constructor" << endl;}

        // Assembles the matrix
        void assembleStorage()
        { cout << "cscSpMat::matVec" << endl; return NULL; }

        // Performs matrix-vector multiplication
        vec_ptr matVec(const vec_ptr x) override
        { cout << "cscSpMat::matVec" << endl; return NULL; }

        // Csc sparse matrix destructor
        ~cscSparseMatrix()
        { cout << "cscSpMat::destructor" << endl;}
>>>>>>> 5710149469d4fd78c0926c19d673bfcd0e5c4849

        //Print the csc_matrix
        void printMatrix();

<<<<<<< HEAD
        //Return the csc_matrix
        vector<vector<T>> get_csc_matrix();
=======
>>>>>>> 5710149469d4fd78c0926c19d673bfcd0e5c4849
};
