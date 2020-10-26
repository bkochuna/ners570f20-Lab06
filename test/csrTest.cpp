#include <iostream>
#include "sparsemat.hpp"
#include "csrsparsemat.hpp"

int main() {
  cout << "Before scopint unit" << endl;
  {
    cout << "Before constructor" << endl;
    csrSparseMatrix<double> A(100,100);
    A.setCoefficient(1,1,1);

    A.assembleStorage();

    A.setCoefficient(1,1,4);
    A.assembleStorage();
    
    cout << "After constructor" << endl;
  }

  cout << "After scoping unit" << endl;
}
