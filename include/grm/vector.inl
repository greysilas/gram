

namespace grm {

    /* Default constructor; fill vector with 0s */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector() {
        
        elements.fill(0);

    }


    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector(T scalar) {

        elements.fill(scalar);

    }

    template<typename T, uint32_t Dim>
    T Vector<T, Dim>::magnitude() {

        return vec::magnitude((*this));   
     

    }

    template<typename T, uint32_t Dim>
    void Vector<T, Dim>::normalize() {

       return vec::normalize((*this));

    }
    
    template<typename T, uint32_t Dim>
    bool Vector<T,Dim>::isUnit() {

       return vec::isUnit((*this));
    
    }

    template<typename T, uint32_t Dim>
    T Vector<T, Dim>::dot(const Vector<T, Dim>& vec) {
        
        return vec::dot((*this), vec);

    }


    template<typename T, uint32_t Dim>
    T& Vector<T, Dim>::operator[](uint32_t index) {
     
        return elements[index];
    
    }
    
    
    template<typename T, uint32_t Dim>
    const T& Vector<T, Dim>::operator[](uint32_t index) const {
    
        return elements[index];
   
    }

   

 
  

}