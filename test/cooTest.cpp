#include <iostream>
#include <numeric>

#include "sparsemat.hpp"
#include "coosparsemat.hpp"

int main() {

  // Test #1 
  // constructor
  const unsigned int n=10;
  CooSparseMatrix<double> A(n,n);

  // Test #2
  // test returns vector size
  A.setCoefficient(1,1,1);
  A.assembleStorage();
  auto test_vec = std::make_shared<std::vector<double>>(n,0);
  auto y = A.matVec(test_vec);
  if (y->size() != n) {
    std::cout << "Test #2 FAILED returned vector size :" << y->size();
    std::cout << "\nMatrix size: " << n << std::endl; 
    return 2;
  }

  // Test #3
  // setCoefficient, assembleStorage, and matVec
  test_vec->at(1) = 1;
  y = A.matVec(test_vec);
  auto sum = std::accumulate(y->begin(), y->end(), 0);
  if (sum != 1) {
    std::cout << "Test #3 FAILED with value: " << sum << std::endl;
    return 3;
  }

  // Test #3 
  // repeated setCoefficient and assembleStorage
  A.setCoefficient(0,0,3);
  A.setCoefficient(1,1,3);
  A.setCoefficient(1,2,3);
  A.setCoefficient(2,1,3);
  A.setCoefficient(2,3,3);
  A.assembleStorage();
  test_vec->at(3) = 1;
  y = A.matVec(test_vec);
  sum = std::accumulate(y->begin(), y->end(), 0);
  if (y->at(0 != 0 || y->at(1) != 3 || y->at(2) != 6 || sum != 9)) {
    std::cout << "Test #4 FAILED with values: " << std::endl;
    std::cout << "y[0] = " << y->at(0) << std::endl;
    std::cout << "y[1] = " << y->at(1) << std::endl;
    std::cout << "y[2] = " << y->at(2) << std::endl;
    std::cout << "sum = " << sum << std::endl;
    return 4;
  }

  // Test #5
  // Try matVec on state besides assembled 
  A.setCoefficient(0,0,3);
  bool caught = false;
  try {
    y = A.matVec(test_vec);
  }
  catch (const std::runtime_error error) {
    // An error should be thrown
    caught = true;
  }
  if (!caught) {
    std::cout << "Test #5 FAILED, no expection thrown "
                 "for bad state calling matVec." << std::endl;
    return 5;
  }

  // All tests pass
  return 0;
}
