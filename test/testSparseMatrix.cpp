#include <iostream>
#include "sparsemat.hpp"

using namespace std;

int main() {
    cout << "Before scoping unit" << endl;
    {

       cout << "Before constructor" << endl;
       SpMV::SparseMatrix<double> A(100,100);
       cout << "After constructor" << endl;

    }
    cout << "After scoping unit" << endl;

    return 0
}
