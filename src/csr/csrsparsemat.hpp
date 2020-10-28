#include <iostream>
#include "../sparsemat.hpp"

using namespace std;

template <class fp_type>
class csrSparseMatrix : public SpMV::SparseMatrix<fp_type>
{
    private:
        void _unAssemble()
	{ cout << "csrSpMat::unAssemble" << endl; }
    public:
	typedef typename SpMV::SparseMatrix<fp_type>::vec_ptr vec_ptr;
	
        //Constructor - receives two inputs: element, number of rows and number of columns
        //Builds CSR sparse matrix based on the input information
        csrSparseMatrix(const size_t nrows, const size_t ncols) :
	    SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
            { cout << "csrSpMat::constructor" << endl;}

	// Assembles the matrix
	void assembleStorage()
	{ cout << "csrSpMat::assembleStorage" << endl;}

	// Performs matrix-vector multiplication
	vec_ptr matVec(const vec_ptr x) override
	{ cout << "csrSpMat::matVec" << endl; return NULL; }

	// Csr Sparse Matrix destructor
        ~csrSparseMatrix()
        { cout << "csrSpMat::destructor" << endl; }

};
