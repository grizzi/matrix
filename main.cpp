#include <iostream>
#include "include/matrix.h"
#include "include/matrix_templated.h"

int main() {
    Matrix test_matrix(3, 3, 1.0);
    test_matrix.print();
    test_matrix(1, 1) = 2;
    test_matrix.print();
    try{
        test_matrix(5,5) = 0;
    }
    catch(const std::invalid_argument& e){
        std::cout << e.what();
    }

    // test also ostream printing
    std::cout << "Sum" << std::endl;
    Matrix A(3, 3, 1.0);
    Matrix B(3, 3, 2.0);
    Matrix C = A + B;
    C(0,0) = -1.0;
    C(0,1) = -1.0;
    C(0,2) = -1.0;
    std::cout << C;

    // transpose
    Matrix Ct = C.transpose();
    std::cout << Ct;

    // templated matrix
    Matrixt<int> Mint(3, 3, 1.9);  // -> will perform floor rounding to integer
    std::cout << Mint;

    Matrixt<double> Mdouble(3, 3, 1.9);
    std::cout << Mdouble;

    // specialized char matrix
    Matrixt<char> Mchar(3, 3, 'a');
    std::cout << Mchar;

}