#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class EllpackSparseMatrix {

  private:
    vector<vector<T>> EllpackMatrix;
  public:
    // Constructor - receives two inputs: elements array, column index array
    // builds the ellpack
    EllpackSparseMatrix(const vector<T> & elementVector, const vector<size_t> & colIndex) : public SparseMatrix<T>;
   
    // Destructor
    ~EllpackSparseMatrix()
 
    // Print Matrix
    void printMatrix();
    
    // Return ellpack matrix
    vector<vector<T>> getEllpackMatrix();

};
