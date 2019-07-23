#pragma once

#include "../matrix.h"
#include "../common/matrix_functions.h"

#include "vec3.h"

namespace grm {

    typedef Matrix<float, 3, 3>     Mat3;
    typedef Matrix<int, 3, 3>       IMat3;


    template<typename T>
    class Matrix<T, 3,3> {

    public:

         /**
         * @brief Default constructor that sets all elements to 0
         */
        Matrix();

        /**
         * @brief Explicit Member Constructor
         * Sets all the members to the specified values
         * @param e00 value at R0 C0
         * @param e01 value at R0 C1
         * @param e02 value at R0 C2
         * @param e10 value at R1 C0
         * @param e11 value at R1 C1
         * @param e12 value at R1 C2
         * @param e20 value at R2 C0
         * @param e21 value at R2 C1
         * @param e22 value at R2 C2
         */
        Matrix  (   T e00, T e01, T e02,      
                    T e10, T e11, T e12,
                    T e20, T e21, T e22
                );

        /**
         * @brief Row Vector Constructor
         * Sets the rows of the matrix to the specified vectors
         * @param row1 First row vector
         * @param row2 Second row vector
         * @param row3 Third row vector
         */
        Matrix  (   const Vec3& row1,
                    const Vec3& row2,
                    const Vec3& row3
                );
        
        /**
         * @brief Constructor that fills the rows with the given vector
         * @params vec The vector whose contents will be mapped to the rows 
         */
        Matrix(const Vec3& vec);


        /**
         * @brief Calculate and return the tranpose
         * @returns the tranposed version of the matrix
         */
        Matrix<T, 3, 3> getTranspose();

        /**
         * @brief Check if matrix is symmetric
         * A matrix is symmetric if it is equal to its transpose
         * @returns true if matrix is symmetric
         */
        bool isSymmetric();
     
     
        /**
         * @brief Check if matrix is antisymmetric
         * A matrix is antisymmetric if it is equal to its transpose when negated
         * @returns true if matrix is antisymmetric
         */
        bool isAntisymmetric();

        /**
         * @brief Operator overload for accesing elements
         * Given [i][j], returns the element in the ith row and jth column
         * @param i Returns the vector in the ith row 
         */
        Vec3& operator[](uint32_t i);


        /**
         * @brief Operator overload for accesing elements
         * Given [i][j], returns the element in the ith row and jth column
         * @param i Returns the vector in the ith row 
         */
        const Vec3& operator[](uint32_t i) const;





        
        std::array<Vec3, 3> elements;


    };

}


#include "mat3x3.inl"