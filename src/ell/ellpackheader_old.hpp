#include <vector>
#include <iostream>

using namespace std;

template <class fp_type>
class EllpackSparseMatrix : public SpMV::SparseMatrix<fp_type> {

  private:
    vector<vector<T>> EllpackMatrix;
    void _unAssemble();
  public:
    // Constructor - receives two inputs: elements array, column index array
    

//    EllpackSparseMatrix(const vector<T> & elementVector, const vector<size_t> & colIndex) : SpMV::SparseMatrix<fp_type>::SparseMatrix<nrows, ncols> {

    EllpackSparseMatrix(const size_t nrow, const size_t ncols) : SpMV::SparseMatrix<fp_type>::SparseMatrix(nrows, ncols) {

	cout << "EllpackSparseMatrix::constructor" << endl;
}
   
    // Destructor
    ~EllpackSparseMatrix();
{
	cout << "EllpackSparseMatrix::destructor" << endl;
}
 
    // Assemble storage
    void assembleStorage();

    vec_ptr matVec(const vec_ptr x) override 

    // Print Matrix
    void printMatrix();
    
    // Return ellpack matrix
    vector<vector<T>> getEllpackMatrix();

};
