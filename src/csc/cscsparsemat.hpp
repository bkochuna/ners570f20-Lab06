#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class CscSparseMatrix{
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
