#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class ellpackSparseMatrix {

  private:
    vector<vector<T>> ellpackMatrix;
  public:
    // Constructor - receives two inputs: elements array, column index array
    // builds the ellpack
    ellpackSparseMatrix(const vector<T> & elementVector, const vector<size_t> & colIndex);
    
    void printMatrix();
    
    vector<vector<T>> getEllpackMatrix();

};
