#pragma once

#include <stdint.h>
#include <array>

#include "vector.h"
#include "./common/matrix_functions.h"


namespace grm {
    
    /**
     * @brief Primary template class for a matrix
     * creates an NxM matrix
     */
    template<typename T, uint32_t Rows, uint32_t Cols>
    class Matrix {

        public:

        /**
         * @brief Default constructor that sets all elements to 0
         */
        Matrix();

        /**
         * @brief Constructor that fills the rows with the given vector
         * @params vec The vector whose contents will be mapped to the rows 
         */
        Matrix(const Vector<T, Cols>& vec);


        /**
         * @brief Calculate and return the tranpose
         * @returns the tranposed version of the matrix
         */
        Matrix<T, Cols, Rows> getTranspose();

        /**
         * @brief Operator overload for accesing elements
         * Given [i][j], returns the element in the ith row and jth column
         * @param i Returns the vector in the ith row 
         */
        Vector<T, Cols>& operator[](uint32_t i);


        /**
         * @brief Operator overload for accesing elements
         * Given [i][j], returns the element in the ith row and jth column
         * @param i Returns the vector in the ith row 
         */
        const Vector<T, Cols>& operator[](uint32_t i) const;




        
        std::array<Vector<T, Cols>, Rows> elements;


    };

}


#include "matrix.inl"