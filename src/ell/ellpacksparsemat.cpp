#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const size_t nrows, const size_t ncols) :
	SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{
	cout << "Called EllpackSparseMatrix<fp_type> constructor" << endl;

	_ellpackMatrix = EllpackSparseMatrix;

};

template <class fp_type>
void EllpackSparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, fp_type aij)
{
	if (row >= _nrows || col >= _ncolumns)
	{
		cout << "Invalid operation, row or column number exceeds size of array" << endl;
		return 1;
	}

	size_t sRowSize = EllpackMatrix[row].size();

	if (sRowSize == 0)
	{
		EllpackMatrix[row].push_back(aij);
		EllpackIndexMatrix[row].push_back(col);
	}
	else
	{
		for (int iI = 0; iI < sRowSize; iI++)
		{
			if (EllpackIndexMatrix[row][iI] > col)
			{
				EllpackMatrix[row].insert(iI, aij);
				EllpackIndexMatrix[row].insert(iI, column);
				break;
			}
		}
	}

	return 0;

};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
	cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
