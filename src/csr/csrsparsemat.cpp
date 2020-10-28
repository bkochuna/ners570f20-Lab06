#include <iostream>
#include "csrsparsemat.hpp"
#include "../sparsemat.hpp"

using namespace std;

template class csrSparseMatrix<float>;
template class csrSparseMatrix<double>;

double csrMethod(const int nrows,
                 const vector<double> & element_vec,
                 const vector<double> & row_vec,
                 const vector<int> & col_vec,
                 const vector<int> & d_vec){
            //three main inputs are the element vector (element_vec),
            // the column index vector (col_vec), and the row index vector (row_vec),
            // and the fourth is a single column vector that serves to give a result
            // Ax=b where x is d_vec and b is csr_matrix result
            int k;
            int i;
            double** csr_matrix[nrows];
            // csr method taken from 
            // http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/3-C/sparse.html
            for (k = 0; k < nrows; k++)
                csr_matrix[k] = 0; // sets all initital values to 0
                          
            //main loops for creating the csr matrix from the vector values
            for (i = 0; i < nrows; i++){  
                for (k = row_vec[i]; k < row_vec[i+1]; k++){  
                    csr_matrix[i] = csr_matrix[i] + element_vec[k]*d_vec[col_vec[k]];
                }  
            }
            //returning the matrix or rather vector that was created
            return csr_matrix;
        };

int main(int nrows, int ncols, double **coeff_matrix){
        //inputs are number of columns (ncols), number of rows (nrows), and some coefficient value

        int i;
        int j;
        
        csrSparseMatrix<double> A(nrows,ncols);
        for (i=0; i < nrows; i++){
            for (j=0; i < ncols; j++){
                A.setCoefficient(i,j,coeff_matrix[i][j]);
            }
        }
        


}
