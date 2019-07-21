#pragma once

#include <stdint.h>

#include "epsilon.h"


namespace grm {
    
    // Forward declaration of the vector template
    template<typename T, uint32_t Dim>
    class Vector;

    


    /**
     * @brief Calculates the magnitude of the vector
     * @param vector The vector whose magnitude will be calculated
     * @returns the magnitude of the vector
     */  
    template<typename T, uint32_t Dim>
    T magnitude(const Vector<T, Dim>& vector);

    template<typename T, uint32_t Dim>
    void normalize(Vector<T, Dim>& vector);

    template<typename T, uint32_t Dim>
    bool isUnit(const Vector<T, Dim>& vector);



    /* Operator Overloading */
 
    
    /**
     * @brief Scalar multiplication
     * Multiplies all components by the parameter given
     * @param scalar The scalar value that scales the components
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T,Dim>& vec, T scalar);

    /**
     * @brief Vector multiplication
     * Component-wise multiplication between the object vector and the parameter
     * @param vector The vector that will be multplied against the object vector
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Scalar Division
     * Divides all components by the parameter given
     * @param scalar The scalar value that divides the components
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T,Dim>& vec, T scalar);

    /**
     * @brief Vector Division
     * Component-wise division between the object vector and the parameter
     * @param vector The vector that will be divided against the object vector
     * @returns A new result vector
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

        /**
     * @brief Vector Addition
     * Performs vector addition between object vector and parameter vector
     * @param vector The vector that will be added with object vector
     * @returns A new result vector
     */       
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator+(const Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

        /**
     * @brief Vector Subtraction
     * Performs vector subtraction between object vector and parameter vector
     * @param vector The vector that will be subtracted with object vector
     * @returns A new result vector
     */    
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator-(const Vector<T,Dim>& vec1, const Vector<T,Dim>& vec2);


    /**
     * @brief Assignment-Scalar Multiplication overload
     * Performs vector scalar multiplication between object vector and parameter vector
     * @param vector The scalar value that will be multiplied with object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=( Vector<T,Dim>& vec,T scalar);

    /**
     * @brief Assignment-Vector Multiplication overload
     * Performs vector Multiplication between object vector and parameter vector
     * @param vector The vector that will be multiplied with the object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=( Vector<T,Dim>& vec1,const Vector<T, Dim>& vec2);


    /**
     * @brief Assignment-Scalar Division overload
     * Performs vector scalar division between object vector and parameter vector
     * @param vector The scalar value that will be divided with object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=( Vector<T,Dim>& vec, T scalar);


    /**
     * @brief Assignment-Vector Division overload
     * Performs vector division between object vector and parameter vector
     * @param vector The vector that will be divded with the object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=( Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Assignment-Addition overload
     * Performs vector addition between object vector and parameter vector
     * @param vector The vector that will be added with the object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator+=( Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);

    /**
     * @brief Assignment-Subtraction overload
     * Performs vector subtraction between object vector and parameter vector
     * @param vector The vector that will be subtracted with the object vector
     * @returns The instance of the object that calls
     */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator-=( Vector<T,Dim>& vec1, const Vector<T, Dim>& vec2);




}


#include "vector_functions.inl"