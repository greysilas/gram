#pragma once

#include "../vector.h"
#include "../common/vector_functions.h"



namespace grm {

    /* Typedefs */
    typedef Vector<float,3> vec3;
    typedef Vector<int,3> ivec3;



    template<typename T>
    class Vector<T, 3> {

        public:

        Vector();
        Vector(T x, T y, T z);

        T magnitude();

        void normalize();

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
			std::array<T, 3> components;
			struct {
				T x;
				T y;
				T z;

			};
		};
        

    };
}


#include "vec3.inl"