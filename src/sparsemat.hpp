#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <cstddef>

namespace SpMV
{

template <class fp_type>
class SparseMatrix
{

    private:
        size_t _nrows = -1;
        size_t _ncols = -1;
        size_t _nnz   = -1;


        //"private" method for inverse operation of assembleStorage
        virtual void _unAssemble()=0;

    public:
        //This is the constructor
        SparseMatrix(const size_t nrows, const size_t ncols);
        //This is the destructor
       ~SparseMatrix();


        //assembleStorage is a pure virtual function.
        //This means it must be implemented on the subclasses
        virtual void assembleStorage()=0;


        //Interface for matVec y<-A*x
        //also a pure virtual function
        virtual fp_type*  matVec(const fp_type* x)=0;


};

}
#endif
