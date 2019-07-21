#pragma once

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
         * Sets all components to 0 value.
         */
        Vector();

    
        /**
         * @brief Scalar constructor
         * Initializes all the components of the vector to the parameter given
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
         * @brief Operator overload that allows typical array-indexing
         * @param index The index to access  
         */
        T& operator[](uint32_t index);

        
        /**
         * @brief Operator overload that allows typical array-indexing
         * @param index The index to access  
         */
        const T& operator[](uint32_t index) const;

        
        
        
        std::array<T, Dim> components;  

    };

 
 

}
#include "vector.inl"