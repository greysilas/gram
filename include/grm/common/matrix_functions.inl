 
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

    // Matrix-Matrix Multiplication
    // NxP * PxM = NxM
    template<typename T, uint32_t N, uint32_t P, uint32_t M>
    Matrix<T, N, M> operator*(const Matrix<T, N, P>& mat1, const Matrix<T, P, M>& mat2) {
        
        Matrix<T, N, M> resultMat;

        for(uint32_t i = 0; i < N; i++) {
            for(uint32_t j = 0; j < M; j++) {
                T productSum = 0;
                for(uint32_t k = 0; k < P; k++) {
                    productSum += mat1[i][k] * mat2[k][j];   
                }
                resultMat[i][j] = productSum;
            }
        }


        return resultMat;
    }

   

    // Mat3x3 Specialized Multiplication
    // Specialized to not use loops; faster than general version
    template<typename T>
    Matrix<T, 3, 3> operator*(const Matrix<T, 3, 3>& mat1, const Matrix<T, 3, 3>& mat2) {

		 Matrix<T, 3, 3> resultMat  ( 
                                        (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0] + mat1[0][2] * mat2[2][0]), // First row
                                        (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1] + mat1[0][2] * mat2[2][1]),
                                        (mat1[0][0] * mat2[0][2] + mat1[0][1] * mat2[1][2] + mat1[0][2] * mat2[2][2]),

                                        (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0] + mat1[1][2] * mat2[2][0]), // Second Row
                                        (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1] + mat1[1][2] * mat2[2][1]),
                                        (mat1[1][0] * mat2[0][2] + mat1[1][1] * mat2[1][2] + mat1[1][2] * mat2[2][2]),

                                        (mat1[2][0] * mat2[0][0] + mat1[2][1] * mat2[1][0] + mat1[2][2] * mat2[2][0]), // Third row
                                        (mat1[2][0] * mat2[0][1] + mat1[2][1] * mat2[1][1] + mat1[2][2] * mat2[2][1]),
                                        (mat1[2][0] * mat2[0][2] + mat1[2][1] * mat2[1][2] + mat1[2][2] * mat2[2][2])

                                    );

        
        return resultMat;

    }

    
    
    // Matrix-Vector Multiplication
    template<typename T, uint32_t Rows, uint32_t Cols>
    Vector<T, Rows> operator*(const Matrix<T, Rows, Cols>& mat, const Vector<T, Cols>& vector) {

       Vector<T, Rows> resultVec;
        
        // Extract each row vector and multiply by column 
        for(uint32_t i = 0; i < Rows; i++) {
            
            T productSum = 0;
            for(uint32_t j = 0; j < Cols; j++) {
                productSum += mat[i][j] * vector[j];
            }
            
            resultVec[i] = productSum;
        }

        return resultVec;

    }

    #include <iostream>
    // Mat3x3-Vec3 Specialized Multiplication 
    // Specialized to not use loops; faster than general version
    template<typename T>
    Vector<T, 3> operator*(const Matrix<T, 3, 3>& mat, const Vector<T, 3>& vec) {

        std::cout << "Special " << std::endl;

        Vector<T, 3> resultVec      (
                                        (mat[0][0] * vec[0] + mat[0][1] * vec[1] + mat[0][2] * vec[2]), // X component
                                        (mat[1][0] * vec[0] + mat[1][1] * vec[1] + mat[1][2] * vec[2]), // Y component
                                        (mat[2][0] * vec[0] + mat[2][1] * vec[1] + mat[2][2] * vec[2])  // Z component

                                    );

        return resultVec;

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