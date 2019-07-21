 
namespace grm {


    // Return tranpose of a matrix
    // Given matrix element [i][j]
    // Tranpose element is [j][i]

    template<typename T, uint32_t Rows, uint32_t Cols>
    Matrix<T, Cols, Rows> getTranspose(const Matrix<T, Rows, Cols>& mat) {

        Matrix<T, Cols, Rows> trans;

        for(uint32_t i = 0; i < Rows; i++) {

            for(uint32_t j = 0; j < Cols; j++) {

                trans[j][i] = mat[i][j];

            }    


        }

        return trans;

    }

}