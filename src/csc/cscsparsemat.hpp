#include <vector>
#include <iostream>
#include "sparsemat.hpp"

using namespace std;

template<class fp_type>
class cscSparseMatrix : public SpMV::SparseMatrix<fp_type>
{
    private:
        vector<vector<T>> csc_matrix;
    public:
        //Constructor - receives three inputs: element, col pointer, row idx vectors
        //Builds CSC sparce matrix based on the input information
        CscSparseMatrix(const vector<T> & element_vec, const vector<int> & colp_vec, const vector<int> & row_vec);

        //Print the csc_matrix
        void printMatrix();

        //Return the csc_matrix
        vector<vector<T>> get_csc_matrix();
};
