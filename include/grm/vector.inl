

namespace grm {

    /* Default constructor; fill vector with 0s */
    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector() {
        
        m_components.fill(0);

    }

  /*
  
    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector(const Vector<T,Dim>& vector) {

        for(size_t i = 0; i < ) {

        }

    }
    
    */

    template<typename T, uint32_t Dim>
    Vector<T, Dim>::Vector(T scalar) {

        m_components.fill(scalar);

    }

    

}