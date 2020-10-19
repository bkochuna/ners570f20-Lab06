#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class CooSparseMatrix{
    private:
        vector<vector<T>> coo_matrix;
    public:
        //Constructor - receives three inputs: element, col idx, row idx vectors
        //Builds COO sparce matrix based on the input information
        CooSparseMatrix(const vector<T> & element_vec, const vector<int> & col_vec, const vector<int> & row_vec);
    
        //Print the coo_matrix
        void printMatrix();
    
        //Return the coo_matrix
        vector<vector<T>> get_coo_matrix();
};
