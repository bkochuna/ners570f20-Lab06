#include <vector>
#include <iostream>

using namespace std;

template <typename fp_type>
class EllpackSparseMatrix {

  private:
    const
    vector<vector<fp_type>> EllpackMatrix;
    vector<vector<fp_type>> EllpackIndexMatrix;
  public:
    // Constructor - receives two inputs: elements array, column index array
    // builds the ellpack
    EllpackSparseMatrix(const size_t nrows, const size_t ncols);
   
    // Destructor
    ~EllpackSparseMatrix()
 
    // Print Matrix
    void printMatrix();
    
    // Return ellpack matrix
    vector<vector<T>> getEllpackMatrix();

};
