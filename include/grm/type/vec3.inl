
namespace grm {

    template<typename T>
    Vector<T,3>::Vector() {
        
        elements.fill(0);

    }

    template<typename T>
    Vector<T,3>::Vector(T scalar) {
        elements.fill(scalar);
    }

    template<typename T>
    Vector<T,3>::Vector(T x, T y, T z) {
        elements[0] = x;
        elements[1] = y;
        elements[2] = z;
    }
 

	template<typename T>
	T Vector<T,3>::magnitude() {
		
		return vec::magnitude((*this));

	}

    template<typename T>
    void Vector<T,3>::normalize() {
		return vec::normalize((*this));
    }

    template<typename T>
    bool Vector<T, 3>::isUnit() {
    
        return vec::isUnit((*this));
    
    }

   
    template<typename T>
    T Vector<T, 3>::dot(const Vector<T, 3>& vec) {
        return (elements[0] * vec[0] + elements[1] * vec[1] + elements[2] * vec[2]);
    }
    
    template<typename T>
    Vector<T,3> Vector<T, 3>::cross(const Vector<T, 3>& vec) {
        
        return Vector<T, 3> (
                                elements[1] * vec[2] - elements[2] * vec[1],
                                elements[2] * vec[0] - elements[0] * vec[2],
                                elements[0] * vec[1] - elements[1] * vec[0]
                            );


    }

    
    template<typename T>
    T& Vector<T, 3>::operator[](uint32_t index) {
        return elements[index];
    }
    
    
    template<typename T>
    const T& Vector<T, 3>::operator[](uint32_t index) const {
        return elements[index];
    }

 
 

}