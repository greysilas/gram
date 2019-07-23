#pragma once

#include <stdint.h>
#include <cmath>

namespace grm {
        
    // Forward declare the matrix class
    template<typename T, uint32_t Rows, uint32_t Cols>
    class Matrix;



    namespace mat {
        
        /**
         * @brief Tranpose the given matrix
         * @param mat The matrix to transpose
         * @returns the transposed parameter matrix
         */
        template<typename T, uint32_t Rows, uint32_t Cols>
        Matrix<T, Cols, Rows> getTranspose(const Matrix<T, Rows, Cols>& mat);


        /**
         * @brief Check if given matrix is symmetric
         * A given matrix is symmetric if it is equal to its transpose
         * @returns true if matrix is symmetric
         */
        template<typename T, uint32_t Rows, uint32_t Cols>
        bool isSymmetric(const Matrix<T, Rows, Cols>& mat);


        /**
         * @brief Check if given matrix is antisymmetric
         * A given matrix is antisymmetric if it is equal to its transpose when negated
         * @returns true if matrix is antisymmetric
         */
        template<typename T, uint32_t Rows, uint32_t Cols>
        bool isAntisymmetric(const Matrix<T, Rows, Cols>& mat);

        


    }



    // Operator Overloading

    /**
     * @brief Matrix equality operator
     * Checks if two matrices are equal
     * Two matrices A and B are equal only if given any index [i][j], A[i][j] == B[i][j]
     * @returns True if matrices are equal 
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    bool operator==(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2);

    
    /**
     * @brief Performs Matrix-Scalar Multiplication
     * Multiplies every element of the matrix with the scalar
     * @returns A new result matrix
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator*(const Matrix<T, Rows, Cols>& mat, T scalar);
    

    /**
     * @brief Performs Matrix-Matrix Multiplication
     * @note Number of columns in first matrix MUST be equal to number of rows in second matrix
     * @returns A new result matrix
     */
    template<typename T, uint32_t N, uint32_t P, uint32_t M>
    Matrix<T, N, M> operator*(const Matrix<T, N, P>& mat1, const Matrix<T, P, M>& mat2);

    /**
     * @brief Specialized Matrix-Matrix operator for two 3x3 Matrices
     * @returns a new result matrix
     */
    template<typename T>
    Matrix<T, 3, 3> operator*(const Matrix<T, 3, 3>& mat1, const Matrix<T, 3, 3>& mat2);


    /**
     * @brief Performs Matrix-Vector Multiplication
     * @note Vector dimension MUST be equal to the number of columns of the matrix. It can be assumed the vector is a column vector
     * @returns A new result vector
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    Vector<T,Rows> operator*(const Matrix<T, Rows, Cols>& mat, const Vector<T, Cols>& vector);

    /**
     * @brief Specialized Matrix-Vector Multiplication for Mat3x3 and Vec3
     * @returns A new result Vec3
     */
    template<typename T>
    Vector<T, 3> operator*(const Matrix<T, 3, 3>& mat, const Vector<T, 3>& vec);


    /**
     * @brief Performs Matrix-Matrix Addition
     * @return A new result matrix
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2);

    /**
     * @brief Performs Matrix-Matrix Subtraction
     * @return A new result matrix
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& mat1, const Matrix<T, Rows, Cols>& mat2);



    

}


#include "matrix_functions.inl"