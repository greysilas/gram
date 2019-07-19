#pragma once

#include <cmath>

#define EPSILON_DEFAULT 0.00005

namespace grm {

    /**
     * @brief Performs an equality check between two operands
     * @param op1 First operand
     * @param op2 Second operand
     * @param epsilon Minimum difference value for operands to be considered equal
     * @returns true if |op2 - op1| < epsilon
     * 
     */
    template<typename T>
    bool epsilonEqual(T op1, T op2, float epsilon = EPSILON_DEFAULT);

    

}


#include "epsilon.inl"