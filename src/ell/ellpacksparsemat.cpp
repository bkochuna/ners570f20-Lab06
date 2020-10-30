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

	// For each entry in the pair, data map
	for (size_t iI = 0; iI < iSize; iI++)
	{
		size_t iRow = _buildCoeff[iI][0][0]; //entry, 0=pair, 0=row
		size_t iCol = _buildCoeff[iI][0][1]; //entry, 0=pair, 1=col
		fp_type dData = _buildCoeff[iI][1]; //entry, 1=data

		vvEllpackMatrix[iRow].push_back(dData); //add data to data matrix at row iRow
		vvEllpackIndexMatrix[iRow].push_back(iCol); // add column informaton to index matrix at row iRow
	}
};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
	cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
