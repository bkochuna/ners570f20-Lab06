#include <iostream>
#include "sparsemat.hpp"

using namespace std;

template <class fp_type>
class testSpMat : public SpMV::SparseMatrix<fp_type>
{
    public:
        // Define an alias for the gross type that templating produces
        typedef typename SpMV::SparseMatrix<fp_type>::vec_ptr vec_ptr;
        //Define constructor to use base class constructor
        testSpMat(const size_t nrows, const size_t ncols) :
            SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
            { cout << "testSpMat::constructor" << endl; }

       ~testSpMat()
        {
            cout << "testSpMat::destructor" << endl;
        }

        void assembleStorage()
        {
            cout << this->_buildCoeff[ make_pair(1,1) ] << endl;
            cout << this->_buildCoeff[ make_pair(1,2) ] << endl;
            cout << this->_buildCoeff[ make_pair(2,1) ] << endl;
            cout << this->_buildCoeff[ make_pair(2,2) ] << endl;
            this->_state = SpMV::assembled;
        }

        vec_ptr matVec(const vec_ptr x) override
        { return NULL; }

    private:
        void _unAssemble()
        { 
            cout << "testSpMat::_unAssemble" << endl;
            this->_state = SpMV::building;
        }
};


int main() {
    cout << "Before scoping unit" << endl;
    {

       cout << "Before constructor" << endl;
       //SpMV::SparseMatrix<double> A(100,100);
       testSpMat<double> A(100,100);

       A.setCoefficient(1,1,1.0);
       A.setCoefficient(1,2,2.0);
       A.setCoefficient(2,1,3.0);

       A.assembleStorage();

       A.setCoefficient(1,1,4.0);
       A.assembleStorage();

       cout << "After constructor" << endl;

    }
    cout << "After scoping unit" << endl;

    return 0;
}
