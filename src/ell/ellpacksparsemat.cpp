#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const size_t nrows, const size_t ncols, const vector <fp_type> elementVector, const vector <size_t> colIndex) :
	SparseMatrix<T>(nrows, ncols)
{
	cout << "Called EllpackSparseMatrix<fp_type> constructor" << endl;

	_ellpackMatrix = EllpackSparseMatrix;

};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
<<<<<<< HEAD
	cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
}
=======
  cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
>>>>>>> cf26870e4a1718df83623d042627e9d50922d9c1
