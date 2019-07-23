
namespace grm {


    // Default constructor
    template<typename T>
    Matrix<T, 3, 3>::Matrix() {
        
        elements.fill(Vector<T, 3>(0));

    }

    // Explicit Values constructor 
    template<typename T>
    Matrix<T, 3, 3>::Matrix (   T e00, T e01, T e02,      
                                T e10, T e11, T e12,
                                T e20, T e21, T e22
                            ) 
    {

        elements[0] = Vector<T, 3>  (e00, e01, e02);
        elements[1] = Vector<T, 3>  (e10, e11, e12);
        elements[2] = Vector<T, 3>  (e20, e21, e22);

    }    

 

    // Row Vector constructors
    template<typename T>
    Matrix<T, 3, 3>::Matrix(   const Vec3& row1,
                                const Vec3& row2,
                                const Vec3& row3
                            )
    {
        elements[0] = row1;
        elements[1] = row2;
        elements[2] = row3;
    }

     // Vector Constructor - Fill all rows with given vector
    template<typename T>
    Matrix<T, 3, 3>::Matrix(const Vec3& vec) {

        elements.fill(vec);

    }

    template<typename T>
    Matrix<T, 3, 3> Matrix<T, 3, 3>::getTranspose() {
        return mat::getTranspose((*this));
    }

    template<typename T>
    bool Matrix<T, 3, 3>::isSymmetric() {
        return mat::isSymmetric((*this));
    }

    template<typename T>
    bool Matrix<T, 3, 3>::isAntisymmetric() {
        return mat::isAntisymmetric((*this));
    }

        // Return the ith vector
    template<typename T>
    Vec3& Matrix<T, 3, 3>::operator[](uint32_t i) {
        return elements[i];
    }

    // Returns the ith vector
    template<typename T>
    const Vec3& Matrix<T, 3, 3>::operator[](uint32_t i) const {
        return elements[i];
    }





        


    

}