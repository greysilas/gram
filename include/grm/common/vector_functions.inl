

namespace grm {

    namespace vec {
        
        // Calculate Magnitude of given vector
        template<typename T, uint32_t Dim>
        T magnitude(const Vector<T, Dim>& vector) {
            // Square sum of the components
            T sqSum = 0;

            for(uint32_t i = 0 ; i < Dim; i++) {
                sqSum += (vector[i] * vector[i]);
            } 

            return std::sqrt(sqSum);
        }

        // Normalize given vector
        template<typename T, uint32_t Dim>
        void normalize(Vector<T, Dim>& vector) {
            T mag = vector.magnitude();
            if(mag == 0) return;

            vector = vector / mag;
        }


        // Return true if given vector is boolean
        template<typename T, uint32_t Dim>
        bool isUnit(const Vector<T, Dim>& vector) {

            return epsilonEqual(magnitude(vector), 1.0f);

        }
 
       // Dot product
        template<typename T, uint32_t Dim>
        T dot(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
            T productSum = 0;
            
            for(uint32_t i = 0; i < Dim; i++) {
                productSum += vec1[i] * vec2[i];
            }

            return productSum;
        }

        // Vector Projection
        template<typename T, uint32_t Dim>
        Vector<T, Dim> project(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {

            return (  vec2 * (dot(vec1,vec2) / dot(vec2,vec2))  );

        }

        // Vector Rejection
        template<typename T, uint32_t Dim>
        Vector<T, Dim> reject(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
            return (vec1 - ( vec2 * (dot(vec1,vec2) / dot(vec2,vec2))));
        }

        
    } // Namespace vec

    /*** Operator Overloading  ***/


    // Vector-Scalar Multiplication
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T, Dim>& vec, T scalar) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec[i] * scalar;
        }

        return resultVec;
    }

   
    //  Vec3-Scalar Multiplication
    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3>& vec, T scalar) {
        Vector<T, 3> resultVec;
        resultVec[0] = vec[0] * scalar;
        resultVec[1] = vec[1] * scalar;
        resultVec[2] = vec[2] * scalar;
        return resultVec;
    }


    // Vector-Vector Multiplication
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec1[i] * vec2[i];
        }

        return resultVec;
    }

    // Vec3-Vec3 Multiplication
    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3>& vec1, const Vector<T, 3>& vec2) {
        Vector<T, 3> resultVec;
        resultVec[0] = vec1[0] * vec2[0];
        resultVec[1] = vec1[1] * vec2[1];
        resultVec[2] = vec1[2] * vec2[2];
        return resultVec;
    }

    // Vector-Scalar Division
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T,Dim>& vec, T scalar) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec[i] / scalar;
        }

        return resultVec;
    }

    // Vector-Vector Divison
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator/(const Vector<T, Dim>& vec1, const Vector<T, Dim> vec2) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec1[i] / vec2[i];
        }

        return resultVec;
    }

    // Vector Addition
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator+(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec1[i] + vec2[i];
        }
        return resultVec;
    }


    // Vector Subtraction
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator-(const Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec1[i] - vec2[i];
        }
        return resultVec;
    }

    // Scalar Mult Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=(Vector<T, Dim>& vec, T scalar) {
        vec = vec * scalar;
        return vec;
    }

    // Vector Mult Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator*=(Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        vec1 = vec1 * vec2;
        return vec1;
    }

    // Scalar Division Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=(Vector<T, Dim>& vec, T scalar) {
        vec = vec / scalar;
        return vec;
    }

    // Vector Division Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator/=(Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        vec1 = vec1 / vec2;
        return vec1;
    }

    // Vector Addition Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator+=(Vector<T, Dim>& vec1, const Vector<T,Dim>& vec2) {
        vec1 = vec1 + vec2;
        return vec1;
    }

    // Vector Subtraction Compound Assignment
    template<typename T, uint32_t Dim>
    Vector<T, Dim>& operator-=(Vector<T, Dim>& vec1, const Vector<T, Dim>& vec2) {
        vec1 = vec1 - vec2;
        return vec1;
    }








} // Namespace grm