#include <iostream>
#include "ellpacksparsemat.hpp"

using namespace std;
using namespace SpMV;

template <class fp_type>
EllpackSparseMatrix<fp_type>::EllpackSparseMatrix(const size_t nrows, const size_t ncols) :
	SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
{
	cout << "Called EllpackSparseMatrix<fp_type> constructor" << endl;

	// _ellpackMatrix = EllpackSparseMatrix; // don't know what this is

};

template <class fp_type>
void EllpackSparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, fp_type aij)
{
	if (row >= _nrows || col >= _ncolumns)
	{
		cout << "Invalid operation, row or column number exceeds size of array" << endl;
		throw "Invalid operation, row or column number exceeds size of array";
	}

	size_t sRowSize = EllpackMatrix[row].size();

	if (sRowSize == 0)
	{
		EllpackMatrix[row].push_back(aij);
		EllpackIndexMatrix[row].push_back(col);
	}
	else
	{
		for (size_t sI = 0; sI < sRowSize; sI++)
		{
			if (EllpackIndexMatrix[row][sI] > col)
			{
				EllpackMatrix[row].insert(sI, aij);
				EllpackIndexMatrix[row].insert(sI, col);
				break;
			}
		}
	}

};

template <class fp_type>
fp_type EllpackIndexMatrix<fp_type>::getCoefficient(const size_t row, const size_t col)
{
	size_t sRow = row;
	size_t sRowSize = EllpackIndexMatrix[row].size();
	for (size_t sI = 0; sI < sRowSize; sI++)
	{
		if (EllpackIndexMatrix[row][sI] == col) return EllpackMatrix[row][sI];
	}
	return 0;
};

template <class fp_type>
EllpackSparseMatrix<fp_type>::~EllpackSparseMatrix()
{
	cout << "Called EllpackSparseMatrix<fp_type> destructor" << endl;
};
