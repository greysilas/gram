#pragma once

#include <stdint.h>
#include <cmath>

namespace grm {

    // Forward declare the matrix class
    template<typename T, uint32_t Rows, uint32_t Cols>
    class Matrix;


    /**
     * @brief Tranpose the given matrix
     * @param mat The matrix to transpose
     * @returns the transposed parameter matrix
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Cols, Rows> getTranspose(const Matrix<T, Rows, Cols>& mat);




}


#include "matrix_functions.inl"