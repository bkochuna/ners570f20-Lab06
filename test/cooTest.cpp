#include <iostream>
#include "sparsemat.hpp"
#include "coosparsemat.hpp"

int main() {
  cout << "Before scoping unit" << endl;
  {
    cout << "Before constructor" << endl;
    const unsigned int n=100;
    CooSparseMatrix<double> A(n,n);

    A.setCoefficient(1,1,1);
    A.assembleStorage();

    A.setCoefficient(1,1,4);
    A.setCoefficient(1,2,5);
    A.assembleStorage();
    
    vector<double> x(n);
    std::shared_ptr<vector<double>> y;
    for(int i=0;i<n;i++){
	    x.at(i) = 1;
    };

    y = A.matVec(std::make_shared<vector<double>>(x));

    cout << "For x=1 (n=100) :" << y->size() << endl;
    for(int i=0;i<n;i++){
	    cout << "y_" << i << " : " << y->at(i) << endl;
    };
    cout << "After constructor" << endl;
  }

  cout << "After scoping unit" << endl;
}
