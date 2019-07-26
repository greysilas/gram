#pragma once

#include <stdint.h>
#include <array>
#include <cmath>

#include "./common/epsilon.h"
#include "./common/vector_functions.h"


namespace grm {

    /**
     *  @brief Primary vector template class
     *     
     *   The primary vector template contains the operations and defintions of a vector that are independent of 
     *   a vector's size.
     * 
     */

    template<typename T, uint32_t Dim>
    class Vector {

        public:

        
        
        /**
         * @brief Default constructor
         * Sets all elements to 0 value.
         */
        Vector();

    
        /**
         * @brief Scalar constructor
         * Initializes all the elements of the vector to the parameter given
         * @param scalar The scalar value used to initialize the vector
         */
        Vector(T scalar);


        /**
         * @brief Returns the magnitude of the vector
         */
        T magnitude();

        /**
         * @brief Normalizes the vector to a unit length
         */
        void normalize();

        /**
         * @brief returns true if vector is of unit length
         */
        bool isUnit();

        /**
         * @brief Performs dot product with object vector and given vector
         * @param vector The second operand vector
         * @returns The result scalar
         */
        T dot(const Vector<T, Dim>& vec);

        /**
         * @brief Projects the first vector onto the second
         * @param vec The vector that the object vector is being projected on
         * @returns A new result vector parallel to vec
         */
        Vector<T, Dim> project(const Vector<T, Dim>& vec);
        
        /**
         * @brief Rejects the first vector onto the second
         * @param vec The vector that the object vector is being rejected on
         * @returns A new result vector perpendicular to vec
         */
        Vector<T, Dim> reject(const Vector<T, Dim>& vec);


        /**
         * @brief Operator overload that allows typical array-indexing
         * @param index The index to access  
         */
        T& operator[](uint32_t index);

        
        /**
         * @brief Operator overload that allows typical array-indexing
         * @param index The index to access  
         */
        const T& operator[](uint32_t index) const;

        
        
        
        std::array<T, Dim> elements;  

    };

 
 

}
#include "vector.inl"