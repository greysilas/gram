

namespace grm {

    /* Default constructor; fill vector with 0s */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector() {
        
        components.fill(0);

    }


    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector(T scalar) {

        components.fill(scalar);

    }

    template<typename T, uint32_t Dim>
    T Vector<T, Dim>::magnitude() {

        return grm::magnitude((*this));   
     

    }

    template<typename T, uint32_t Dim>
    void Vector<T, Dim>::normalize() {

       return grm::normalize((*this));

    }
    
    template<typename T, uint32_t Dim>
    bool Vector<T,Dim>::isUnit() {

       return grm::isUnit((*this));
    
    }


    template<typename T, uint32_t Dim>
    T& Vector<T, Dim>::operator[](uint32_t index) {
        return components[index];
    }
    
    
    template<typename T, uint32_t Dim>
    const T& Vector<T, Dim>::operator[](uint32_t index) const {
        return components[index];
    }

   

 
  

}