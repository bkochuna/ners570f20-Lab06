#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const size_t nrows, const size_t ncols, const vector <fp_type> elementVector, const vector <size_t> colIndex) :
	SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{

	// stuff goes here!

};

