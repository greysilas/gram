

namespace grm {

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
    
    // Vector-Scalar Multiplication
    template<typename T, uint32_t Dim>
    Vector<T, Dim> operator*(const Vector<T, Dim>& vec, T scalar) {
        Vector<T, Dim> resultVec;
        for(uint32_t i = 0; i < Dim; i++) {
            resultVec[i] = vec[i] * scalar;
        }

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








}