#include <vector>
#include <iostream>

template <class fp_type>
class ellSparseMat : public SpMV::SparseMatrix<fp_type>
{

  public:
    ellSparseMat(const size_t nrows, const size_t ncols) : SpMv::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols);

    ~ellSparseMat();

     virtual void assembleStorage()=0;

     virtual vec_ptr matVec(const vec_ptr x)=0;

     virtual vec_ptr matVec(const fp_type* x) final;

  protected:

     virtual void _unAssemble()=0;

}
