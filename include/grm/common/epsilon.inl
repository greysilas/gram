
namespace grm {

    template<typename T>
    bool epsilonEqual(T op1, T op2, float epsilon) {
        return ( std::abs(op2 - op1) < epsilon );
    }

}