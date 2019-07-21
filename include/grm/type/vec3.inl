
namespace grm {

    template<typename T>
    Vector<T,3>::Vector() {
        
        components.fill(0);

    }

    template<typename T>
    Vector<T,3>::Vector(T x, T y, T z) {
        components[0] = x;
        components[1] = y;
        components[2] = z;
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
        return components[index];
    }
    
    
    template<typename T>
    const T& Vector<T, 3>::operator[](uint32_t index) const {
        return components[index];
    }

 
 

}