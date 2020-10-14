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

    public:
        //This is the constructor
        SparseMatrix(const size_t nrows, const size_t ncols);
        //This is the destructor
       ~SparseMatrix();

};

}
#endif
