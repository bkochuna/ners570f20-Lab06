#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <cstddef>
#include <utility> //for std::pair
#include <map>     //for std::map


namespace SpMV
{

/* Enumerations for SparseMatrix object state
 *
 * undefined   - this state should never be encountered
 * initialized - state following completion of the constructor
 * building    - state of object after calling setCoefficients
 * assembled   - state of object following call to assembleStorage
 */
enum MatrixState {undefined,initialized,building,assembled};

// SparseMatrix Class definition
template <class fp_type>
class SparseMatrix
{

    protected:
        size_t _nrows = 0;
        size_t _ncols = 0;
        size_t _nnz   = 0;

        MatrixState _state = undefined;

        //Use map container accessed by row,col pair to store
        //coefficients during building state
        std::map< std::pair<size_t,size_t>, fp_type> _buildCoeff;

        //"private" method for inverse operation of assembleStorage
        virtual void _unAssemble()=0;

    public:
        //This is the constructor
        SparseMatrix(const size_t nrows, const size_t ncols);
        //This is the destructor
       ~SparseMatrix();

        //Set matrix values one at a time
        void setCoefficient(const size_t row, const size_t col, fp_type aij);

        //assembleStorage is a pure virtual function.
        //This means it must be implemented on the subclasses
        virtual void assembleStorage()=0;


        //Interface for matVec y<-A*x
        //also a pure virtual function
        virtual fp_type*  matVec(const fp_type* x)=0;


};

}
#endif
