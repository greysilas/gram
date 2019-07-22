 
namespace grm {

    namespace mat {
       
        // Return tranpose of a matrix
        // Given matrix element [i][j]
        // Tranpose element is [j][i]
        template<typename T, uint32_t Rows, uint32_t Cols>
        Matrix<T, Cols, Rows> getTranspose(const Matrix<T, Rows, Cols>& mat) {

            Matrix<T, Cols, Rows> trans;

            for(uint32_t i = 0; i < Rows; i++) {

                for(uint32_t j = 0; j < Cols; j++) {

                    trans[j][i] = mat[i][j];

                }    


            }

            return trans;

        }


        // Matrix Symmetry Check
        template<typename T, uint32_t Rows, uint32_t Cols>
        bool isSymmetric(const Matrix<T, Rows, Cols>& mat) {

            // Only square matrices can be symmetric
            if(Rows != Cols) return false;

            if(mat == getTranspose(mat)) return true;
            else return false;


        }


        // Matrix Antisymmetry Check
        // A matrix is antisymmetric if given any value at index [i][j], the transpose value is -[i][j]
        template<typename T, uint32_t Rows, uint32_t Cols>
        bool isAntisymmetric(const Matrix<T, Rows, Cols>& mat) {

            // Only square matrices can be antisymmetric
            if(Rows != Cols) return false;

            Matrix<T, Cols, Rows> transpose = getTranspose(mat);
            
            for(uint32_t i = 0; i < Rows; i++) {
                
                for(uint32_t j = 0; j < Cols; j++) {
                
                    if(mat[i][j] != -transpose[i][j]) return false;
                
                }
            }

            return true;


        }


    } // Namespace mat
   

    // Matrix equality
    template<typename T, uint32_t Rows, uint32_t Cols>
    bool operator==(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2) {

        for(uint32_t i = 0; i < Rows; i++) {
            for(uint32_t j = 0; j < Cols; j++) {

                if(mat1[i][j] != mat2[i][j]) return false;

            }
        }

        return true;
    }

    // Matrix-Scalar Multiplication
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator*(const Matrix<T, Rows, Cols>& mat, T scalar) {

        Matrix<T, Rows, Cols> resultMat;

        for(uint32_t i = 0; i < Rows; i++) {
            for(uint32_t j = 0; j < Cols; j++) {
                resultMat[i][j] = mat[i][j] * scalar;
            }
        }

        return resultMat;    

    }
    

    // Matrix-Matrix Addition
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2) {
        
        // Only matrices of same dimensions can be added

        Matrix<T, Rows, Cols> resultMat;

        for(uint32_t i = 0; i < Rows; i++) {
            for(uint32_t j = 0; j < Cols; j++) {
                resultMat[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        return resultMat;    

    }


    
    // Matrix-Matrix Subtraction
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2) {
        
        // Only matrices of same dimensions can be added

        Matrix<T, Rows, Cols> resultMat;

        for(uint32_t i = 0; i < Rows; i++) {
            for(uint32_t j = 0; j < Cols; j++) {
                resultMat[i][j] = mat1[i][j] - mat2[i][j];
            }
        }

        return resultMat;    

    }


}   // Namespace grm