#include <iostream>
#include "cscsparsemat.hpp"
#include "sparsemat.hpp"

using namespace std;

template class cscSparseMatrix<float>;
template class cscSparseMatrix<double>;

template <class fp_type>

//This class defines a sparse matrix in the CSC format
class cscSparsMatrix : public SpMV::SparsMatrix<fp_type>
{
    private:
        void_unAssemble()
        { cout << "cscSpaMat::unAssemble" << endl; }
    
    public:
    
    //Construct Matrix
    cscSparseMatrix(const size_t nrows, const size_t ncols) :
        SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows,ncols)
        { cout << "cscSpaMat::"=constructor" << endl; }
        
    //Assemble Matrix
    void assembleStorage()
    { cout << "cscSpaMat::matrixVector" << endl; }
    
    //Perform Matrix Calculation
    
    
    //Deconstruct Matrix
    ~cscSparseMatrix()
     { cout << "cscSpaMat::destructor" << endl; }
    
