#pragma once

#include <stdint.h>

#include "epsilon.h"


namespace grm {
    
    // Forward declaration of the vector template
    template<typename T, uint32_t Dim>
    class Vector;

    // All vector functions are stored within the vec namespace
    namespace vec {

    
        /**
         * @brief Calculates the magnitude of the vector
         * @param vector The vector whose magnitude will be calculated
         * @returns the magnitude of the vector
         */  
        template<typename T, uint32_t Dim>
        T magnitude(const Vector<T, Dim>& vector);

        /**
         * @brief Normalizes the given vector to a unit length
         * @param vector The vector to normalize
         */
        template<typename T, uint32_t Dim>
        void normalize(Vector<T, Dim>& vector);

        /**
         * @brief Check if given vector is of unit length
         * @param vector The vector that will be tested for unit length
         * @returns True if given vector has unit length
         */
        template<typename T, uint32_t Dim>
        bool isUnit(const Vector<T, Dim>& vector);

        /**
         * @brief Performs dot product between two vectors
         * @param vec1 The first operand vector
         * @param vec2 The second operand vector
         * @returns The result scalar
         */
        template<typename T, uint32_t Dim>
        T dot(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2);
 
        
    }

    /* Operator Overloading */
 
    
    /**
     * @brief Scalar multiplication
     * Multiplies all components of vector by the parameter given
     * @param vec The operand vector
     * @param scalar The operand scalar
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T,Dim>& vec, T scalar);

    /**
     * @brief 3D Vector-Scalar Specialized Multiplication
     * @param vec The operand vector
     * @param scalar The operand scalar
     * @returns A new result Vec3
     */
    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3>& vec, T scalar);

    /**
     * @brief Vector multiplication
     * Component-wise multiplication between the object vector and the parameter
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief 3D Vector Specialized Multiplication
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns A new result Vec3
     */
    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3>& vec1, const Vector<T, 3>& vec2);

    /**
     * @brief Scalar Division
     * Divides all components by the parameter given
     * @param vec The operand vector
     * @param scalar The operand scalar
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T,Dim>& vec, T scalar);

    /**
     * @brief Vector Division
     * Component-wise division between the object vector and the parameter
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Vector Addition
     * Performs vector addition between object vector and parameter vector
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns A new result vector
     */       
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator+(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

        /**
     * @brief Vector Subtraction
     * Performs vector subtraction between object vector and parameter vector
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns A new result vector
     */    
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator-(const Vector<T,Dim>& vec1, const Vector<T,Dim>& vec2);


    /**
     * @brief Assignment-Scalar Multiplication overload
     * Performs vector scalar multiplication and assigns value to left hand operand
     * @param vec The operand vector
     * @param scalar The operand scalar
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=( Vector<T,Dim>& vec,T scalar);

    /**
     * @brief Assignment-Vector Multiplication overload
     * Performs vector multiplication between two vectors and assigns value to left hand operand
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=( Vector<T,Dim>& vec1,const Vector<T, Dim>& vec2);


    /**
     * @brief Assignment-Scalar Division overload
     * Performs vector-scalar division and assigns value to left hand operand
     * @param vec The operand vector
     * @param scalar The operand scalar
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=( Vector<T,Dim>& vec, T scalar);


    /**
     * @brief Assignment-Vector Division overload
     * Performs vector division between two vectors and assigns value to left hand operand
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=(Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Assignment-Addition overload
     * Performs vector addition  between two vectors and assigns value to left hand operand
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator+=( Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Assignment-Subtraction overload
     * Performs vector subtraction between two vectors and assigns value to left hand operand
     * @param vec1 The first operand vector
     * @param vec2 The second operand vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator-=( Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);


  


}


#include "vector_functions.inl"