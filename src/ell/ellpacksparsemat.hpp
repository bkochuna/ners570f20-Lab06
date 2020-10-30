#include <vector>
#include <iostream>

using namespace std;

template <typename fp_type>
class EllpackSparseMatrix
{

private:
    const
    vector<vector<fp_type>> vvEllpackMatrix;
    vector<vector<size_t>> vvEllpackIndexMatrix;
public:
    // Constructor - receives two inputs: elements array, column index array
    // builds the ellpack
    EllpackSparseMatrix(const size_t nrows, const size_t ncols) : SpMv::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols);
    ~EllpackSparseMatrix();

    virtual void assembleStorage();

    virtual vec_ptr matVec(const vec_ptr x);


protected:

    virtual void _unAssemble();

};
