#pragma once

#include "../vector.h"
#include "../common/vector_functions.h"



namespace grm {

    /* Typedefs */
    typedef Vector<float,3> Vec3;
    typedef Vector<int,3>   IVec3;



    template<typename T>
    class Vector<T, 3> {

        public:

        Vector();
        Vector(T scalar);
        Vector(T x, T y, T z);

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
        T dot(const Vector<T, 3>& vec);


        /**
         * @brief Performs cross product with object vector and given vector
         * @param vector The second operand vector
         * @returns The result vector
         */
        Vector<T, 3> cross(const Vector<T, 3>& vec);

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
        

 

		union {
			std::array<T, 3> elements;
			struct {
				T x;
				T y;
				T z;

			};
		};
        

    };
}


#include "vec3.inl"