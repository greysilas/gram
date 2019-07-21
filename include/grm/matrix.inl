
namespace grm {

    // Default Constructor - Fill Matrix with 0s
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols>::Matrix() {

        elements.fill(Vector<T, Cols>(0));


    }

    // Vector Constructor - Fill rows with given vector
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Rows, Cols>::Matrix(const Vector<T, Cols>& vec) {

        elements.fill(vec);

    }

    // Return the transposed version of the matrix
    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Cols, Rows> Matrix<T, Rows, Cols>::getTranspose() {
        
        return grm::getTranspose((*this));

    }

    // Return the ith vector
    template<typename T, uint32_t Rows, uint32_t Cols>
    Vector<T, Cols>& Matrix<T, Rows, Cols>::operator[](uint32_t i) {
        return elements[i];
    }

    // Returns the ith vector
    template<typename T, uint32_t Rows, uint32_t Cols>
    const Vector<T, Cols>& Matrix<T, Rows, Cols>::operator[](uint32_t i) const {
        return elements[i];
    }






}