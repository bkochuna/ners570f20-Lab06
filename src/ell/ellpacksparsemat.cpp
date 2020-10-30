#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const size_t nrows, const size_t ncols) :
	: SpMV::_nrows(nrows), SpMV::_ncols(ncols), SpMV::_state(initialized)
{
	cout << "Called EllpackSparseMatrix<fp_type> constructor" << endl;

	// _ellpackMatrix = EllpackSparseMatrix; // don't know what this is

};

~EllpackSparseMatrix()
{
	cout << "Called destructor for EllpackSparseMatrix()" << endl;
};

virtual void EllpackIndexMatrix::assembleStorage();
{
	cout << "Called assembleStorage() method for Ellpack" << endl;
	size_t iSize = _buildCoeff.size();

	// Initial allocation of memory for the (outer) vector, both to store the indices as well as to store the data.
	vvEllpackMatrix.allocate(_nrows);
	vvEllpackIndexMatrix.allocate(_nrows);

	for (size_t iI = 0; iI < iSize; iI++)
	{
		size_t iRow = _buildCoeff[iI][0][0];
		size_t iCol = _buildCoeff[iI][0][1];
		fp_type dData = _buildCoeff[iI][1];
		vvEllpackMatrix[iRow].push_back(dData);
		vvEllpackIndexMatrix[iRow].push_back(iCol);
	}
};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
	cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
