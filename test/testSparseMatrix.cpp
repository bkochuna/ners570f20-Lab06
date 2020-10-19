#include <iostream>
#include "sparsemat.hpp"

using namespace std;

template <class fp_type>
class testSpMat : public SpMV::SparseMatrix<fp_type>
{
    public:
        //Define constructor to use base class constructor
        testSpMat(const size_t nrows, const size_t ncols) :
            SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
            { cout << "testSpMat::subclass constructor" << endl; }

        void assembleStorage()
            { cout << "testSpMat::no op assembly storage" << endl; }

        fp_type* matVec(const fp_type* x)
        { return NULL; }

    private:
        void _unAssemble()
            { cout << "testSpMat::no op unassemble" << endl; }
};


int main() {
    cout << "Before scoping unit" << endl;
    {

       cout << "Before constructor" << endl;
       //SpMV::SparseMatrix<double> A(100,100);
       testSpMat<double> A(100,100);
       cout << "After constructor" << endl;

    }
    cout << "After scoping unit" << endl;

    return 0;
}
