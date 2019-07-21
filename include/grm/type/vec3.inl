
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
		
		return grm::magnitude((*this));

	}

    template<typename T>
    void Vector<T,3>::normalize() {
		return grm::normalize((*this));
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