#pragma once

#include <array>
#include <cmath>

#include "./common/epsilon.h"

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
         * @brief Copy constructor
         * @param cpyVector The vector whose contents will be copied
         */
      //  Vector(const Vector<T, Dim>& cpyVector)

        /**
         * @brief Type-agnostic copy constructor
         * Static casts the parameter to the type of vector
         * @param cpyVector the vector whose contents will be copied
         */
        //template<typename U>
       // Vector(const Vector<U, Dim>& cpyVector); 

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

        /**
         * @brief Scalar multiplication
         * Multiplies all components by the parameter given
         * @param scalar The scalar value that scales the components
         * @returns A new result vector
         */
        Vector<T, Dim> operator*(T scalar);

        /**
         * @brief Vector multiplication
         * Component-wise multiplication between the object vector and the parameter
         * @param vector The vector that will be multplied against the object vector
         * @returns A new result vector
         */
        Vector<T, Dim> operator*(const Vector<T, Dim>& vector);

        /**
         * @brief Scalar Division
         * Divides all components by the parameter given
         * @param scalar The scalar value that divides the components
         * @returns A new result vector
         */
        Vector<T, Dim> operator/(T scalar);

        /**
         * @brief Vector Division
         * Component-wise division between the object vector and the parameter
         * @param vector The vector that will be divided against the object vector
         * @returns A new result vector
         */
        Vector<T, Dim> operator/(const Vector<T, Dim>& vector);

         /**
         * @brief Vector Addition
         * Performs vector addition between object vector and parameter vector
         * @param vector The vector that will be added with object vector
         * @returns A new result vector
         */       
        Vector<T, Dim> operator+(const Vector<T, Dim>& vector);

         /**
         * @brief Vector Subtraction
         * Performs vector subtraction between object vector and parameter vector
         * @param vector The vector that will be subtracted with object vector
         * @returns A new result vector
         */    
        Vector<T, Dim> operator-(const Vector<T,Dim>& vector);


        /**
         * @brief Assignment-Scalar Multiplication overload
         * Performs vector scalar multiplication between object vector and parameter vector
         * @param vector The scalar value that will be multiplied with object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator*=(T scalar);

        /**
         * @brief Assignment-Vector Multiplication overload
         * Performs vector Multiplication between object vector and parameter vector
         * @param vector The vector that will be multiplied with the object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator*=(const Vector<T, Dim>& vector);


        /**
         * @brief Assignment-Scalar Division overload
         * Performs vector scalar division between object vector and parameter vector
         * @param vector The scalar value that will be divided with object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator/=(T scalar);


        /**
         * @brief Assignment-Vector Division overload
         * Performs vector division between object vector and parameter vector
         * @param vector The vector that will be divded with the object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator/=(const Vector<T, Dim>& vector);

        /**
         * @brief Assignment-Addition overload
         * Performs vector addition between object vector and parameter vector
         * @param vector The vector that will be added with the object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator+=(const Vector<T, Dim>& vector);

        /**
         * @brief Assignment-Subtraction overload
         * Performs vector subtraction between object vector and parameter vector
         * @param vector The vector that will be subtracted with the object vector
         * @returns The instance of the object that calls
         */
        Vector<T, Dim>& operator-=(const Vector<T, Dim>& vector);


        private:

            /* Components of the vector. These are publicy accessed by the template specializations or by the [] operator */
            std::array<T, Dim> m_components;  

    };

}



#include "vector.inl"