

namespace grm {

    /* Default constructor; fill vector with 0s */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector() {
        
        m_components.fill(0);

    }


    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector(T scalar) {

        m_components.fill(scalar);

    }

    template<typename T, uint32_t Dim>
    T Vector<T, Dim>::magnitude() {
        
        // Square sum of the components
        T sqSum = 0;
        
        for(T component : m_components) {
            sqSum += (component * component);
        }

        return std::sqrt(sqSum);

    }

    template<typename T, uint32_t Dim>
    void Vector<T, Dim>::normalize() {

        T mag = magnitude();
        if(mag == 0) return;

        *this = *this / magnitude();

    }
    
    template<typename T, uint32_t Dim>
    bool Vector<T,Dim>::isUnit() {
        return epsilonEqual(magnitude(), 1.0f);
    }

    template<typename T, uint32_t Dim>
    T& Vector<T, Dim>::operator[](uint32_t index) {
        return m_components[index];
    }
    
    
    template<typename T, uint32_t Dim>
    const T& Vector<T, Dim>::operator[](uint32_t index) const {
        return m_components[index];
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T,Dim>::operator*(T scalar) {

        Vector<T, Dim> resVec; // Resultant Vector
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] * scalar;
        }

        return resVec;

    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T, Dim>::operator*(const Vector<T, Dim>& vector) {
        
        Vector<T, Dim> resVec; // Resultant Vector
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] * vector[index];
        }

        return resVec;

    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T, Dim>::operator/(T scalar) {
        
        Vector<T, Dim> resVec;
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] / scalar;
        }

        return resVec;

    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T,Dim>::operator/(const Vector<T,Dim>& vector) {
      
        Vector<T, Dim> resVec;
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] / vector[index];
        }
        return resVec;

    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T,Dim>::operator+(const Vector<T, Dim>& vector) {
       
        Vector<T, Dim> resVec;
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] + vector[index];
        }
        return resVec;

    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim> Vector<T, Dim>::operator-(const Vector<T, Dim>& vector) {
        Vector<T, Dim> resVec;
        for(uint32_t index = 0; index < Dim; index++) {
            resVec[index] = m_components[index] - vector[index];
        }
        return resVec;
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator*=(T scalar) {
        (*this) = (*this) * scalar;
        return (*this);
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator*=(const Vector<T,Dim>& vector) {
        (*this) = (*this) * vector;
        return (*this);
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator/=(T scalar) {
        (*this) = (*this) / scalar;
        return (*this);
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator/=(const Vector<T, Dim>& vector) {
        (*this) = (*this) / vector;
        return (*this);
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator+=(const Vector<T, Dim>& vector) {

        (*this) = (*this) + vector;
        return (*this);
    }

    template<typename T, uint32_t Dim>
    Vector<T, Dim>& Vector<T, Dim>::operator-=(const Vector<T, Dim>& vector) {

        (*this) = (*this) - vector;
        return (*this);
    }



}