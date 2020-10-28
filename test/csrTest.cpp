#include <iostream>
#include "sparsemat.hpp"
#include "csrsparsemat.hpp"

int main() {
  int i,j
  // Declare 4 vec_ptrs, x and b for both float and double

  // Test double type
  csrSparseMatrix<double> matD(3,3);

  // Set coefficients -- this assumes indexing starts at 0
  // 1 0 2 
  // 3 4 0 
  // 0 0 5 
  matD.setCoefficient(0,0,1);
  matD.setCoefficient(0,2,2);
  matD.setCoefficient(1,0,3);
  matD.setCoefficient(1,1,4);
  matD.setCoefficient(2,2,5);
  matD.assembleStorage();

  // Set x vector to be x = (1,2,3)

  // Perform matVec multiply

  // Check that b = (7,11,15), if not return error

  // Explicitly call deconstructor for test 
  matD.~csrSparseMatrix;

  // Test float type
  csrSparseMatrix<float> matF(3,3);

  // Set coefficients -- assumes indexing starts at 0
  // 1 2 0
  // 3 0 4
  // 0 5 0
  matF.setCoefficient(0,0,1);
  matF.setCoefficient(0,1,2);
  matF.setCoefficient(1,0,3);
  matF.setCoefficient(1,2,4);
  matF.setCoefficient(2,1,5);
  matF.assembleStorage();

  // Set x vector to be x = (1,2,3)

  // Perform matVec multiply
  
  // Check that b = (5,15,10), if not return error

  // Explicitly call deconstructor for test 
  matF.~csrSparseMatrix;
}
